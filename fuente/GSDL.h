#ifndef GSDL_H
#define GSDL_H

#include "Tipos.h"
#include "GVentana.h"
#include "elementos/GTexto.h"

int iniciarGSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0 || TTF_Init() == -1)
        return -1;
    return 0;
}

void cerrarGSDL()
{
    SDL_Quit();
    //TTF_Quit();
}

#endif /* GSDL_H */
