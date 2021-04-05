#ifndef GESCUCHADORTECLADO_H
#define GESCUCHADORTECLADO_H

#include "GEventoTeclado.h"

class GEscuchadorTeclado
{
  public:

    // Cuando se presiona una tecla.
    // Implementacion para SDL_KEYDOWN en sdl2
    virtual void teclaPresionada(GEventoTeclado *e) = 0;

    // Cuando el puntero esta dentro de una elemento en especifico
    //virtual void tecla(GEventoTeclado *e) = 0;
};


#endif /* GESCUCHADORTECLADO_H */
