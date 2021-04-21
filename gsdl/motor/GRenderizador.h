#ifndef GRENDERIZADOR_H
#define GRENDERIZADOR_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class GRenderizador
{
  private:

    /* Renderizador de SDL */
    SDL_Renderer *grender;

    /* Fuente de texto 1 */
    TTF_Font *gfuente1;
    //std::vector<TTF_Font *> gfuentes;

  public:

    GRenderizador();

    ~GRenderizador();

    /* Retornos e ingresos */
    SDL_Renderer *retGrender() const;

    TTF_Font *retFuente1() const;

    // Inicia el renderizador en la ventana
    void iniciar(SDL_Window *ventana);

    // Cargar la fuentes de texto
    void cargarFuentes();

    // Limpiar la ventana para volver a renderizar
    void limpiar();

    /* Mostrar */
    void renderizar();

    // Crear un contexto de textura
    SDL_Texture *crearTextura(int ancho, int alto);

};

#endif /* GRENDERIZADOR_H */
