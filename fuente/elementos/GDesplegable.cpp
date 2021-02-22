#include "GDesplegable.h"

GDesplegable::GDesplegable() : GElemento()
{
    titulo = new GBoton();
    verLista = false;
}

GDesplegable::GDesplegable(GBoton *t) : GElemento()
{
    titulo = t;
    verLista = false;
}

GDesplegable::~GDesplegable()
{
    delete titulo;
    if (lista.empty() == false)
    {
        for (auto l : lista)
            delete l;
    }
    lista.clear();
}

void GDesplegable::ingPosicion(int x, int y)
{
    titulo->ingPosicion(x, y);
}

void GDesplegable::agregar(GBoton *g)
{
    if (lista.empty() == true)
    {
        // Para agregar el primer elemento hay que calcular los puntos del titulo
        // para poder dibujar uno debajo del otro
        // int pos_y = g->retY() + g->retAlto();
        // TODO: se debe comprobar que no se salga del la ventana
        g->ingPosicion(titulo->retX(), titulo->retY() + titulo->retAlto());
        lista.push_back(g);
    }
    else
    {
        // Para ingresar mas botones que no sean el primero, se obtiene el ultimo boton
        // y de acuerdo a ese, ingresamos el siguiente
        GBoton *ultimo = lista.back();
        g->ingPosicion(ultimo->retX(), ultimo->retY() + ultimo->retAlto());
        lista.push_back(g);
    }
}

void GDesplegable::dibujar(GRenderizador *r)
{
    titulo->dibujar(r);
    if (verLista == true)
    {
        if (lista.empty() == false)
            for (auto l : lista)
                l->dibujar(r);
    }
}

void GDesplegable::controlarEvento(SDL_Event *e)
{
    titulo->controlarEvento(e);
    // Este codigo esta repetido dentro de GBoton
    if (e->type == SDL_MOUSEBUTTONDOWN)
        verLista = true;
}
