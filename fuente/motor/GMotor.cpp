#include "GMotor.h"

GRenderizador *GMotor::gmrender = new GRenderizador();

GMotor::~GMotor()
{
    delete gmrender;
    gmrender = nullptr;
}

int GMotor::iniciarGSDL()
{
    //iniciado = false;
    // Iniciamos el video de SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        return -1;
    }
    
    if (TTF_Init() == -1)
    {
        return -1;
    }

    //iniciado = true;
    return 0;
}

void GMotor::terminarGSDL()
{
    TTF_Quit();
    SDL_Quit();
}
