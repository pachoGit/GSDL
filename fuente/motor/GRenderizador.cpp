#include "GRenderizador.h"

GRenderizador::GRenderizador()
{
    grender = nullptr;
}

GRenderizador::GRenderizador(SDL_Window *ventana)
{
    if (ventana == nullptr)
    {
        SDL_SetError("No se ha creado el SDL_Renderer");
        return;
    }
    grender = SDL_CreateRenderer(ventana, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

GRenderizador::~GRenderizador()
{
    if (grender != nullptr)
        SDL_DestroyRenderer(grender);
}

// Hace lo mismo que el constructor de arriba
void GRenderizador::iniciar(SDL_Window *ventana)
{
    // TODO: Creo que seria importante enviar un mensaje que el renderizador no se creo :D
    if (ventana == nullptr)
    {
        SDL_SetError("No se ha creado el SDL_Renderer");
        return;
    }
    grender = SDL_CreateRenderer(ventana, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
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
