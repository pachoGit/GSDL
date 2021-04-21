#include "GVentana.h"
#include "GConfig.h"
#include <iostream>
#include <SDL2/SDL_ttf.h>

GVentana::GVentana()
{
    titulo = GConfig::titulo_ventana;
    alto = GConfig::alto_ventana;
    ancho = GConfig::ancho_ventana;
    estilo = GESTILO_NINGUNO;
    tipo = GVENTANA_NINGUNO;
    gventana = nullptr;
    renderizador = nullptr;
}

GVentana::GVentana(std::string t)
{
    titulo = t;
    alto = GConfig::alto_ventana;
    ancho = GConfig::ancho_ventana;
    estilo = GESTILO_NINGUNO;
    tipo = GVENTANA_NINGUNO;
    gventana = nullptr;
    renderizador = nullptr;
}

GVentana::GVentana(std::string t, int al, int an)
{
    titulo = t;
    alto = al;
    ancho = an;
    estilo = GESTILO_NINGUNO;
    tipo = GVENTANA_NINGUNO;
    gventana = nullptr;
    renderizador = nullptr;
}

GVentana::~GVentana()
{
    if (gventana != nullptr)
    {
        SDL_DestroyWindow(gventana);
        gventana = nullptr;
    }
    delete renderizador;
    renderizador = nullptr;
}

void GVentana::ingTitulo(std::string t)
{
    titulo = t;
}

void GVentana::ingAlto(int al)
{
    alto = al;
}

void GVentana::ingAncho(int an)
{
    ancho = an;
}

void GVentana::ingEstiloVentana(EstiloVentana e)
{
    estilo = e;
}

// TODO: Talvez se pueda mejorar esto y tambien agregar el parametro TipoVentana
// a alguno de los constructores
void GVentana::ingTipoVentana(TipoVentana t)
{
    tipo = t;
}

// Esta funcion es la que ejecuta casi absolutamente todo, para el iniciado de SDL
void GVentana::mostrar()
{
    // Contruimos la ventana, ademas de iniciar los modulos de SDL y el contexto de
    // renderizado
    if (!construir())
        return;

    for (auto elemento : elementos)
        elemento->construir(renderizador);

    SDL_Event evento;
    bool salir = false;

    while (!salir)
    {
        while (SDL_PollEvent(&evento))
        {
            if (evento.type == SDL_QUIT)
                salir = true;
            for (auto elemento : elementos)
                elemento->controlarEvento(&evento);
        }

        renderizador->limpiar();
        for (auto elemento : elementos)
            elemento->dibujar(renderizador);
        renderizador->renderizar();
    }

    // Esto para multiples ventanas no esta bien, ya que mi idea de multiples ventanas
    // es solo hacer std::vector<GVentana *> ventanas; y al cerrar una ventana,
    // se detendra tambien los modulos de SDL, talvez tenga que hacer que el usuario
    // tenga que especificarlo si o si :(
    SDL_Quit();
}

bool GVentana::construir()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0 || TTF_Init() == -1)
        return false;
    gventana = SDL_CreateWindow(titulo.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                            alto, ancho, tipo);
    renderizador = new GRenderizador;
    renderizador->iniciar(gventana);
    //renderizador->cargarFuentes();
    
    return true;
    
}
