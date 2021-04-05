#ifndef ENTRADATEXTO_H
#define ENTRADATEXTO_H

/* Clase general para la entrada de texto como el campo de texto y el area de texto */

#include "GElemento.h"

class EntradaTexto : public GElemento
{
  private:

    // Color de fondo de la caja de entrada
    GColor colorFondo;

    // Color del texto dentro de la caja de entrada
    GColor colorTexto;

    // EL color del borde de la caja de entrada
    GColor colorBorde;

    // Este es el cursor ("I"): toma esa forma cuando esta sobre la caja
    SDL_Cursor *cursor;

    // El texto contenido en esta caja de entrada
    std::string contenido;

    bool estaEscribiendo;

  public:

    EntradaTexto();

    ~EntradaTexto();

    void ingColorFondo(GColor c);

    void ingColorTexto(GColor c);

    void ingColorBorde(GColor c);

    GColor retColorFondo() const;

    GColor retColorTexto() const;

    GColor retColorBorde() const;

    SDL_Cursor *retCursor();

    std::string retContenido();

    /*
    void dibujar(GRenderizador *r);

    void controlarEvento(SDL_Event *e);
    */
};


#endif /* ENTRADATEXTO_H */
