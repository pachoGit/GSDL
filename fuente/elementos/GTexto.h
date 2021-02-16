#ifndef GTEXTO_H
#define GTEXTO_H

#include <SDL2/SDL_ttf.h>
#include <string>
#include <iostream>
#include "../GConfig.h"
#include "../motor/GRenderizador.h"

#include "GElemento.h"

typedef enum EstiloFuente
{
    GNORMAL    = TTF_STYLE_NORMAL,
    GNEGRITA   = TTF_STYLE_BOLD,
    GITALICA   = TTF_STYLE_ITALIC,
    GSUBRAYADO = TTF_STYLE_UNDERLINE,
    GTACHADO   = TTF_STYLE_STRIKETHROUGH
} EstiloFuente;


// Cadena de caracteres para GSDL

class GTexto : public GElemento
{
  private:

    // Cadena de caracteres
    std::string texto;

    // Un puntero al tipo de fuente
    TTF_Font *fuente;

    // Tamanio de fuente
    int tam;
    
    // Estilo de la fuente - Por defecto GNORMAL
    EstiloFuente estilo;

    // Color de la fuente
    SDL_Color color;

    // Textura del texto
    //SDL_Texture *texto_textura;

    // Espacio que ocupa el texto (textura)
    //SDL_Rect texto_espacio;

  public:

    // Inicia un nuevo objeto con por defecto con:
    // texto  = "Texto"
    // fuente = GConfig::nombre_fuente
    // tam    = GConfig::tam_fuente
    GTexto();

    // Inicia un nuevo objeto con un texto determinado
    GTexto(std::string cad);

    // Inicia un nuevo objeto con un texto y tamanio determinado
    GTexto(std::string cad, unsigned t);

    // Inicia un nuevo objeto con un texto, tamanio y fuente determinado
    GTexto(std::string cad, unsigned t, TTF_Font *f);

    ~GTexto();
    
    //Ingresos y Retornos 
    void ingTexto(std::string cad);
    void ingFuente(std::string nf);
    void ingTam(unsigned t);
    void ingEstilo(int e);
    void ingColor(SDL_Color c);
    void ingPosicion(int x, int y);
            
    std::string retTexto() const;
    TTF_Font *retFuente() const;
    EstiloFuente retEstilo() const;
    SDL_Color retColor() const;

    
    // Dibuja el texto para luego ser presentado
    void dibujar(GRenderizador *r);

    //void dibujar(GVentana *v)
};


#endif /* GTEXTO_H */
