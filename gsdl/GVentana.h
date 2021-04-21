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
    GVENTANA_NINGUNO = SDL_WINDOW_SHOWN // Por defecto
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

    // Titulo de la ventana principal
    std::string titulo;

    // Alto de la ventana en pixeles
    int alto;

    // Ancho de la ventana en pixeles
    int ancho;

    // La ventana
    SDL_Window *gventana;
    
    // El renderizador de la ventana
    GRenderizador *renderizador;

    // Lista de todas las texturas en esta ventana
    std::vector<GElemento *> elementos;

    // Caracteristicas de la ventana
    TipoVentana tipo;

    // La ventana solo puede tener un solo estilo
    EstiloVentana estilo;

    // Banderas para el estado de la ventana
    bool minimizado;

    bool mouseEncima;

  private:

    // Inicia los modulos de SDL, el SDL_Renderer y SDL_Window
    bool construir();

  public:

    /* Constructor por defecto, los valores para la ventana (titulo, ancho y alto) son
     * sacados del archivo de configuracion "Gconfig.cpp
     */
    GVentana();

    /* Constructor con titulo para la ventana */
    GVentana(std::string t);

    /* Constructor con titulo y dimensiones (alto y ancho) para la ventana  */
    GVentana(std::string t, int al, int an);

    ~GVentana();

    /* @param t: Titulo para la ventana */
    void ingTitulo(std::string t);

    /* @param al: Altura de la ventana */
    void ingAlto(int al);

    /* @param an: Anchura de la ventana */
    void ingAncho(int an);

    /* @param e: Estilo de la ventana */
    void ingEstiloVentana(EstiloVentana e);

    /* @param t: Propiedades de la ventana */
    void ingTipoVentana(TipoVentana t);

    /* Muestra la ventana y todo lo que contenga */
    void mostrar();

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
