#include "GBoton.h"
#include "../GConfig.h"
#include <iostream>

GBoton::GBoton() : GElemento()
{
    texto = new GTexto(GConfig::texto_boton);
    color = GConfig::color_boton;
}

GBoton::GBoton(GTexto *t) : GElemento()
{
    texto = t;
    color = GConfig::color_boton;
    tipoEvento = "nada";
    funcion_evento = nullptr;
}

GBoton::GBoton(GTexto *t, GColor c) : GElemento()
{
    texto = t;
    color = c;
}

GBoton::GBoton(std::string t) : GElemento()
{
    texto = new GTexto(t);
    color = GConfig::color_boton;
}


GBoton::~GBoton()
{
    /*
    if (SDL_Surface != nullptr)
        SDL_FreeSurface(fondo);
    */
    if (texto != nullptr)
        delete texto;
}

void GBoton::controlarEvento(SDL_Event *e)
{
    int x, y;
    bool estaAqui = true; // El mouse esta sobre el boton?

    SDL_GetMouseState(&x, &y);

    if (x < retX())
        estaAqui = false;
    else if (x > retX() + retAncho())
        estaAqui = false;
    if (y < retY())
        estaAqui = false;
    else if (y > retY() + retAlto())
        estaAqui = false;

    if (e->type == SDL_MOUSEMOTION)
    {
        if (estaAqui == true)
            color = GConfig::color_boton_mouse;
        else
            color = GConfig::color_boton;
    }
    if (e->type == SDL_MOUSEBUTTONDOWN)
    {
        if (estaAqui == true && tipoEvento.compare("click") == 0)
            funcion_evento();
    }
}

void GBoton::ingColor(GColor c)
{
    color = c;
}

void GBoton::agregarEvento(std::string tipo, FuncionEvento fe)
{
    tipoEvento = tipo;
    funcion_evento = fe;
}

void GBoton::dibujar(GRenderizador *r)
{
    actualizar(r);
    SDL_Rect e = retEspacio();
    SDL_RenderCopy(r->retGrender(), retTextura(), nullptr, &e);
    texto->dibujar(r);
}

void GBoton::actualizar(GRenderizador *r)
{
    // Dependiendo del espacio que ocupe el texto, se genera el espacio del boton
    SDL_Rect espacio_texto = texto->retEspacio();
    SDL_Rect espacio_boton = retEspacio();

    // El alto y ancho del boton es 10 pixeles mas grande que el ancho y alto del texto
    espacio_boton.w = espacio_texto.w + 20;
    espacio_boton.h = espacio_texto.h + 20;

    // La posicion del boton manda, asi que hay que alinear la posicion del texto a la
    // posicion del boton
    texto->ingX(retX() + 10);
    texto->ingY(retY() + 10);
    // Actualizamos el espacio nuevo del boton
    ingEspacio(espacio_boton);

    // Creamos la textura del boton.
    // TODO: Esto debe crearse solo una vez, no en cada ciclo como lo estoy haciendo,
    // necesito el SDL_Renderer para crearlo pero como ven solo aqui es donde tengo
    // acceso a esta variable
    SDL_Texture *t = SDL_CreateTexture(r->retGrender(), SDL_PIXELFORMAT_RGBA8888,
                                       SDL_TEXTUREACCESS_TARGET, retAncho(), retAlto());
    if (!t)
        return;
    // Pintamos el espacio ocupado por el boton.
    SDL_SetRenderTarget(r->retGrender(), t);
    SDL_SetRenderDrawColor(r->retGrender(), color.at(0), color.at(1), color.at(2),
                           color.at(3));

    ingTextura(t);
    SDL_Rect eb = retEspacio();
    SDL_RenderClear(r->retGrender());
    SDL_SetRenderTarget(r->retGrender(), nullptr);
}
