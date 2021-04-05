#ifndef GCAMPOTEXTO_H
#define GCAMPOTEXTO_H

#include "EntradaTexto.h"

class GCampoTexto : public EntradaTexto
{
  public:

    GCampoTexto();

    ~GCampoTexto();
    
    void dibujar(GRenderizador *r);

    void controlarEvento(SDL_Event *e);

    
};

#endif /* CAMPOTEXTO_H */
