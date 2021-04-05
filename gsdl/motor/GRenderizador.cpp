#include "GRenderizador.h"
#include "../GConfig.h"

GRenderizador::GRenderizador()
{
    grender = nullptr;
    gfuente1 = nullptr;
}

GRenderizador::~GRenderizador()
{
    if (grender != nullptr)
        SDL_DestroyRenderer(grender);
    if (gfuente1 != nullptr)
        TTF_CloseFont(gfuente1);
}

SDL_Renderer *GRenderizador::retGrender() const
{
    return grender;
}

TTF_Font *GRenderizador::retFuente1() const
{
    return gfuente1;
}

// Hace lo mismo que el constructor de arriba
void GRenderizador::iniciar(SDL_Window *ventana)
{
    if (ventana == nullptr)
    {
        SDL_SetError("No se ha creado el SDL_Renderer");
        return;
    }
    grender = SDL_CreateRenderer(ventana, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void GRenderizador::cargarFuentes()
{
    gfuente1 = TTF_OpenFont(GConfig::nombre_fuente.c_str(), 12);
    if (!gfuente1)
        SDL_SetError("Fuente no cargada");
}

void GRenderizador::limpiar()
{
    SDL_SetRenderDrawColor(grender, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(grender);
}

void GRenderizador::renderizar()
{
    SDL_RenderPresent(grender);
}
