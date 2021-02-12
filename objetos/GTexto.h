#ifndef GTEXTO_H
#define GTEXTO_H

#include <SDL2/SDL_ttf>
#include <string>
#include <iostream>
#include "../Gconfig.h"

typedef enum EstiloFuente
{
    GNORMAL    = TTF_STYLE_NORMAL,
    GNEGRITA   = TTF_STYLE_BOLD,
    GITALICA   = TTF_STYLE_ITALIC,
    GSUBRAYADO = TTF_STYLE_UNDERLINE,
    GTACHADO   = TTF_STYLE_STRIKETHROUGH
} EstiloFuente;


// Cadena de caracteres para GSDL

class GTexto
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
    

    // Retornos e Ingresos
    void ingTexto(std::string cad);
    void ingFuente(std::string nf);
    void ingTam(unsigned t);
    void ingEstilo(int e);
            

    std::string retTexto() const;
    
};


#endif /* GTEXTO_H */
