#include "GVentana.h"
#include "GConfig.h"
#include <iostream>
#include <SDL2/SDL_ttf.h>

GVentana::GVentana()
{
    titulo = GConfig::titulo_ventana;
    alto = GConfig::alto_ventana;
    ancho = GConfig::ancho_ventana;
    gventana = crearVentana();
    renderizador = new GRenderizador(gventana);
    estilo = GESTILO_NINGUNO;
}

GVentana::GVentana(std::string t)
{
    titulo = t;
    alto = GConfig::alto_ventana;
    ancho = GConfig::ancho_ventana;
    gventana = crearVentana();
    renderizador = new GRenderizador(gventana);
    estilo = GESTILO_NINGUNO;
}

GVentana::GVentana(std::string t, int al, int an)
{
    titulo = t;
    alto = al;
    ancho = an;
    gventana = crearVentana();
    renderizador = new GRenderizador(gventana);
    estilo = GESTILO_NINGUNO;
}

GVentana::~GVentana()
{
    if (gventana != nullptr)
    {
        SDL_DestroyWindow(gventana);
        gventana = nullptr;
    }
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

// Esta funcion es la que ejecuta casi absolutamente todo, para el iniciado de SDL
void GVentana::mostrar()
{
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

    SDL_Quit();
}

SDL_Window *GVentana::crearVentana()
{
    return SDL_CreateWindow(titulo.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                            alto, ancho, SDL_WINDOW_SHOWN);
}

/*
template<typename T>
void GVentana::agregar(T *t)
{
    if (t != nullptr)
        t->dibujar(renderizador);
}
*/
