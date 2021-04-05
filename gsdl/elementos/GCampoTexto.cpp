#include "GCampoTexto.h"
#include "../GConfig.h"

GCampoTexto::GCampoTexto() : EntradaTexto()
{
    ingEspacio(GConfig::espacio_campo);
}

GCampoTexto::~GCampoTexto()
{
}

void GCampoTexto::dibujar(GRenderizador *r)
{
    SDL_Texture *tex = SDL_CreateTexture(r->retGrender(), SDL_PIXELFORMAT_RGBA8888,
                                         SDL_TEXTUREACCESS_TARGET, retAncho(), retAlto());
    if (!tex)
        return;
    SDL_Rect e = retEspacio();
    SDL_SetRenderTarget(r->retGrender(), tex);

    SDL_RenderClear(r->retGrender());
    // Pintamos el borde del cuadro
    GColor cb = retColorBorde();
    SDL_SetRenderDrawColor(r->retGrender(), cb.at(0), cb.at(1),
                           cb.at(2), cb.at(3));
    SDL_RenderDrawRect(r->retGrender(), &e);


    // Pintamos el fondo del cuadro
    GColor cf = retColorFondo();
    SDL_SetRenderDrawColor(r->retGrender(), cf.at(0), cf.at(1),
                           cf.at(2), cf.at(3));
    SDL_RenderFillRect(r->retGrender(), &e);

    ingTextura(tex);
    SDL_SetRenderTarget(r->retGrender(), nullptr);
    SDL_RenderCopy(r->retGrender(), retTextura(), nullptr, &e);
}

void GCampoTexto::controlarEvento(SDL_Event *e)
{
    return;
}
