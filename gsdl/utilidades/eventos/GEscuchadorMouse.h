#ifndef GESCUCHADORMOUSE_H
#define GESCUCHADORMOUSE_H

#include "GEventoMouse.h"

class GEscuchadorMouse
{
  public:

    GEscuchadorMouse()
    {
    }

    ~GEscuchadorMouse()
    {
    }

    // Click
    virtual void clickIzquierdo(GEventoMouse *e) = 0;

    // Anti click
    virtual void clickDerecho(GEventoMouse *e) = 0;

    // El boton izquierdo del mouse se mantiene pulsado
    virtual void izqPulsado(GEventoMouse *e) = 0;

    // El boton derecho del mouse se mantiene pulsado
    virtual void derPulsado(GEventoMouse *e) = 0;

    /*

    // Cuando se suelta algun boton del mouse
    virtual void soltarClick(GEventoMouse *e) = 0;

    // Cuando el puntero esta dentro de una elemento en especifico
    virtual void mouseDentro(GEventoMouse *e) = 0;

    // Cuando el puntero esta fuera de una elemento en especifico
    virtual void mouseFuera(GEventoMouse *e) = 0;
    */

    // Implementar rueda del mouse
    //virtual void rueda(GEventoMouse *e) = 0;
};


#endif /* GESCUCHADORMOUSE_H */
