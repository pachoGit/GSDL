#include "EntradaTexto.h"

EntradaTexto::EntradaTexto() : GElemento()
{
    colorFondo = GConfig::color_fondo_caja;
    colorTexto = GConfig::color_texto_caja;
    colorBorde = GConfig::color_borde_caja;
    cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_IBEAM);
    estaEscribiendo = false;
}

EntradaTexto::~EntradaTexto()
{
    if (cursor != nullptr)
        SDL_FreeCursor(cursor);
}

void EntradaTexto::ingColorFondo(GColor c)
{
    colorFondo = c;
}

void EntradaTexto::ingColorTexto(GColor c)
{
    colorTexto = c;
}

void EntradaTexto::ingColorBorde(GColor c)
{
    colorBorde = c;
}

GColor EntradaTexto::retColorFondo() const
{
    return colorFondo;
}

GColor EntradaTexto::retColorTexto() const
{
    return colorTexto;
}

GColor EntradaTexto::retColorBorde() const
{
    return colorBorde;
}

SDL_Cursor *EntradaTexto::retCursor()
{
    return cursor;
}

std::string EntradaTexto::retContenido()
{
    return contenido;
}

/*
void EntradaTexto::dibujar(GRenderizador *r)
{
}

void EntradaTexto::controlarEvento(SDL_Event *e)
{
    
}
*/
