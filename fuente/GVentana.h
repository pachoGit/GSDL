#ifndef GVENTANA_H
#define GVENTANA_H

#include <SDL2/SDL.h>
#include <string>
#include "motor/GRenderizador.h"

typedef enum TipoVentana
{
    GVENTANA_CAMBIANTE = SDL_WINDOW_RESIZABLE,
    GVENTANA_COMPLETA  = SDL_WINDOW_FULLSCREEN,
} TipoVentana;

/* Simple implementacion del programa principal */

class GVentana
{
  private:
    std::string titulo;

    int alto;

    int ancho;

    // La ventana
    SDL_Window *gventana;
    
    // El renderizador de la ventana
    GRenderizador *renderizador;

    // Lista de todas las texturas en esta ventana
    std::vector<Elementos *> elementos;

  private:
    SDL_Window *crearVentana();

  public:

    GVentana();

    GVentana(std::string t);

    GVentana(std::string t, int al, int an);

    ~GVentana();

    /* Muestra la ventana y todo lo que contenga */
    void mostrar();

    // Agregar cualquier elemento a la ventana
    // botones, paneles, de todo
    /*
    template<typename T>
    void agregar(T *t);
    */

    // Esto deberia ir implementado en el .cpp pero no se como se define una funcion
    // con template, me salia un error al hacerlo...mejor dicho aun me falta investigar :D
    template<typename T>
    void agregar(T *t)
    {
        if (t != nullptr)
            t->dibujar(renderizador);
    }

};

#endif /* GVENTANA_H */
