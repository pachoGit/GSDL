#ifndef GBOTON_H
#define GBOTON_H

#include "GElemento.h"
#include "GTexto.h"

// Prototipo de funcion donde el usuario programara las acciones cuando se genere un
// evento determinado
typedef void (*FuncionEvento)();

class GBoton : public GElemento
{
  private:
    // El fondo del boton, pongo textura por que quien sabe algun dia se implemente con
    // colocar una foto de fondo, pero por el momento solo voy a utilizar simple color
    //SDL_Surface *fondo;

    // Texto contenido en el boton
    // En realidad aqui deberia ser un array de GElementos ya que en un boton puede haber
    // varias texturas. Tal vez algun lo implemente, no deberia ser dificil :D
    GTexto *texto;

    // Color de fondo del boton
    GColor color;

    // Evento personalizado por el usuario
    //TipoEvento evento;
    std::string tipoEvento;

    // Que se hara cuando ocurra un evento determinado?
    FuncionEvento funcion_evento;

  public:
    GBoton();

    GBoton(GTexto *t);

    GBoton(GTexto *t, GColor c);

    GBoton(std::string t);

    ~GBoton();

    void ingColor(GColor c);

    // Tarea definida por el usuario para realizar luego de que se genere
    // el tipo de evento definido por el usuario
    void agregarEvento(std::string tipo, FuncionEvento fe);

    // Dibuja el texto para luego ser presentado
    void dibujar(GRenderizador *r);

    void controlarEvento(SDL_Event *e);
    

  private:

    // Actualizar los elementos del boton
    void actualizar(GRenderizador *r);
};


#endif /* GBOTON_H */
