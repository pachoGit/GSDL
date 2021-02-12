#include "GRenderizador.h"

GRenderizador::GRenderizador()
{
    grender = nullptr;
    gtextura = nullptr;
    gtextura_texto = nullptr;
    gfuente = nullptr;
}

GRenderizador::~GRenderizador()
{
    if (grender != nullptr)
        SDL_DestroyRenderer(grender);
    if (gtextura != nullptr)
        SDL_DestroyTexture(gtextura);
    if (gtextura_texto != nullptr)
        SDL_DestroyTexture(gtextura_texto);
    if (gfuente != nullptr)
        TTF_CloseFont(gfuente);
}

SDL_Renderer *GRenderizador::retGrender()
{
    return grender;
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
