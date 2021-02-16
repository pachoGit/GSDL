#ifndef GMOTOR_H
#define GMOTOR_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "GRenderizador.h"

class GMotor
{
  public:

    /* El SDL_Renderer (GRenderizador) tiene que ser visto y utilizado desde cualquier clase en este
     * proyecto, sin necesidad de crear un objeto. Esta variable se inicializa en
     * GMotor.cpp con un puntero hacia su tipo (GRenderizador) para luego en el archivo
     * GVentana.cpp ser iniciado un nuevo tipo SDL_Renderer
     */
    static GRenderizador *gmrender;
    
  public:

    ~GMotor();
    static int iniciarGSDL();
    static void terminarGSDL();


};


#endif /* GMOTOR_H */
