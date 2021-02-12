#ifndef GRENDERIZADOR_H
#define GRENDERIZADOR_H

#include <SDL2/SDL.h>

class GRenderizador
{
  private:

    /* Renderizador de SDL */
    SDL_Renderer *grender;

    /* Textura para todos los elementos de la aplicacion */
    SDL_Texture *gtextura;

    /* Ayuda para dibujar el texto */
    SDL_Texture *gtextura_texto;
    
  public:
    GRenderizador();
    ~GRenderizador();

    /* Retornos e ingresos */
    SDL_Renderer *retGrender();

    void limpiar();

    /* Mostrar */
    void renderizar();

};

#endif /* GRENDERIZADOR_H */
