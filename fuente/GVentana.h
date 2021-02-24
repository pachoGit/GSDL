#ifndef GVENTANA_H
#define GVENTANA_H

#include <string>
#include <vector>

#include "motor/GRenderizador.h"
#include "elementos/GElemento.h"

typedef enum TipoVentana
{
    GVENTANA_CAMBIANTE = SDL_WINDOW_RESIZABLE,
    GVENTANA_COMPLETA  = SDL_WINDOW_FULLSCREEN,
} TipoVentana;

// Estilo o disenio de la ventana
// TODO: Que estilos de ventana tenemos?
typedef enum EstiloVentana
{
    GESTILO_NINGUNO,
    GESTILO_GRID,
    GESTILO_BORDES
} EstiloVentana;

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
    std::vector<GElemento *> elementos;

    // La ventana solo puede tener un solo estilo
    EstiloVentana estilo;

    // Banderas para el estado de la ventana
    bool minimizado;

    bool mouseEncima;

  private:
    SDL_Window *crearVentana();

  public:

    GVentana();

    GVentana(std::string t);

    GVentana(std::string t, int al, int an);

    ~GVentana();

    void ingTitulo(std::string t);

    void ingAlto(int al);

    void ingAncho(int an);


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
            elementos.push_back(dynamic_cast<GElemento *> (t));
    }

};

#endif /* GVENTANA_H */
