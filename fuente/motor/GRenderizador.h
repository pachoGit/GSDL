#ifndef GRENDERIZADOR_H
#define GRENDERIZADOR_H

#include <SDL2/SDL.h>

class GRenderizador
{
  private:

    /* Renderizador de SDL */
    SDL_Renderer *grender;

  public:

    GRenderizador();
    
    GRenderizador(SDL_Window *ventana);

    ~GRenderizador();

    // Inicia el renderizador en la ventana
    void iniciar(SDL_Window *ventana);

    /* Retornos e ingresos */
    SDL_Renderer *retGrender();

    void limpiar();

    /* Mostrar */
    void renderizar();

};

#endif /* GRENDERIZADOR_H */
