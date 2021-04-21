#ifndef GTEXTO_H
#define GTEXTO_H

#include <SDL2/SDL_ttf.h>
#include <string>
#include <iostream>
#include "../Tipos.h"
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

    // Nombre de la fuente a usar para el texto
    std::string nombre_fuente;
    
    // Tamanio de fuente
    unsigned tam;

    // Color de la fuente
    GColor color;
    
    // Estilo de la fuente - Por defecto GNORMAL
    EstiloFuente estilo;

    //
    TTF_Font *ttf_fuente;

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

    ~GTexto();
    
    //Ingresos y Retornos 
    void ingTexto(std::string cad);

    void ingNombreFuente(std::string nf);

    void ingTam(unsigned t);

    void ingColor(GColor c);

    void ingEstilo(EstiloFuente e);

    void ingTTFFuente(TTF_Font *f);

    std::string retTexto() const;
    
    std::string retNombreFuente() const;

    GColor retColor() const;

    EstiloFuente retEstilo() const;

    // SobreEscritos
    
    void construir(GRenderizador *r);

    void controlarEvento(SDL_Event *e);
    
    // Dibuja el texto para luego ser presentado
    void dibujar(GRenderizador *r);
};


#endif /* GTEXTO_H */
