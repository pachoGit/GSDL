#ifndef GDESPLEGABLE_H
#define GDESPLEGABLE_H

/* Implementacion de un boton con una lista desplegable - en ingles como "dropdown" */

#include "GElemento.h"
#include "GBoton.h"
#include "../motor/GRenderizador.h"
#include <vector>

class GDesplegable : public GElemento
{
  private:

    GBoton *titulo; // El titulo de le boton desplegable
    std::vector<GBoton *> lista; // Lista de botones
    bool verLista; // Bandera para saber si se debe mostrar el menu

  public:
    
    // Constructor por defecto con el boton por defecto
    GDesplegable();
    
    // Constructor con el boton de inicio (titulo)
    GDesplegable(GBoton *t);

    ~GDesplegable();

    // Ingresar la posicion del desplegable
    void ingPosicion(int x, int y);

    // Agregar un nuevo boton a la lista de elementos
    void agregar(GBoton *b);

    void dibujar(GRenderizador *r);

    void controlarEvento(SDL_Event *e);
};

#endif /* GDESPLEGABLE_H */
