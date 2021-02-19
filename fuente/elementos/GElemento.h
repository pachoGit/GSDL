/* Clase general de todos los elementos que se desea para crear una ventana
 * o app para GUI simples
 */

#ifndef GELEMENTO_H
#define GELEMENTO_H

#include <SDL2/SDL.h>
#include "../motor/GRenderizador.h"
#include "../GConfig.h"
//#include "../GVentana.h"

class GElemento
{
  private:
    // La textura del elemento
    SDL_Texture *textura;

    // El espacio ocupado por el elemento
    SDL_Rect espacio;
  public:

    GElemento()
    {
        textura = nullptr;
        espacio = GConfig::espacio_defecto;
    }

    GElemento(SDL_Texture *t, SDL_Rect e)
    {
        textura = t;
        espacio.x = e.x;
        espacio.y = e.y;
        espacio.w = e.w;
        espacio.h = e.h;
    }

    ~GElemento()
    {
        if (textura != nullptr)
            SDL_DestroyTexture(textura);
    }

    void ingTextura(SDL_Texture *t)
    {
        textura = t;
    }

    void ingEspacio(SDL_Rect e)
    {
        espacio = e;
    }

    // Cambiar de posicion el elemento
    void ingPosicion(int x, int y)
    {
        espacio.x = x;
        espacio.y = y;
    }

    // Cambiar el area del elemento
    void ingArea(int alto, int ancho)
    {
        espacio.w = alto;
        espacio.h = ancho;
    }

    void ingX(int x)
    {
        espacio.x = x;
    }

    void ingY(int y)
    {
        espacio.y = y;
    }

    void ingAlto(int alto)
    {
        espacio.w = alto;
    }

    void ingAncho(int ancho)
    {
        espacio.h = ancho;
    }

    int retX() const
    {
        return espacio.x;
    }

    int retY() const
    {
        return espacio.y;
    }

    int retAlto() const
    {
        return espacio.h;
    }

    int retAncho() const
    {
        return espacio.w;
    }

    SDL_Texture *retTextura()
    {
        return textura;
    }

    SDL_Rect retEspacio()
    {
        return espacio;
    }

    // Mostrar el elemento en la ventana
    virtual void dibujar(GRenderizador *r) = 0;
    
    // Controlador de eventos de los distintos elementos de GSDL
    virtual void controlarEvento(SDL_Event *e) = 0;

    // Otra manera de dibujar el elemento
    //virtual void dibujarEn(GVentana *v) = 0;
};

#endif /* GELEMENTO_H */
