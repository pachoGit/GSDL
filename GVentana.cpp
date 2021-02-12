#include "GVentana.h"

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
        }

        
    }
}
