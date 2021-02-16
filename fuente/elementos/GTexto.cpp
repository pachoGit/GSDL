#include "GTexto.h"
#include <iostream>

GTexto::GTexto() : GElemento()
{
    texto = "Texto";
    fuente = TTF_OpenFont(GConfig::nombre_fuente.c_str(), GConfig::tam_fuente);
    if (!fuente)
        std::cout << "No se ha podido cargar la fuente de texto: " << GConfig::nombre_fuente << std::endl;
    tam = GConfig::tam_fuente;
    /* Color por defecto - negro */
    color = GConfig::color_fuente;
}

GTexto::GTexto(std::string cad) : GElemento()
{
    texto = cad;
    fuente = TTF_OpenFont(GConfig::nombre_fuente.c_str(), GConfig::tam_fuente);
    if (!fuente)
        std::cout << "No se ha podido cargar la fuente de texto: " << GConfig::nombre_fuente << std::endl;
    tam = GConfig::tam_fuente;
    /* Color por defecto - negro */
    color = GConfig::color_fuente;
}

GTexto::GTexto(std::string cad, unsigned t) : GElemento()
{
    texto = cad;
    fuente = TTF_OpenFont(GConfig::nombre_fuente.c_str(), GConfig::tam_fuente);
    if (!fuente)
        std::cout << "No se ha podido cargar la fuente de texto: " << GConfig::nombre_fuente << std::endl;
    tam = t;
    /* Color por defecto - negro */
    color = GConfig::color_fuente;
}

GTexto::GTexto(std::string cad, unsigned t, TTF_Font *f)
{
    texto = cad;
    if (f != nullptr)
        fuente = f;
    else
    {
        fuente = TTF_OpenFont(GConfig::nombre_fuente.c_str(), GConfig::tam_fuente);
        if (!fuente)
            std::cout << "No se ha podido cargar la fuente de texto: " << GConfig::nombre_fuente << std::endl;
    }
    tam = t;
    /* Color por defecto - negro */
    color = GConfig::color_fuente;
}

GTexto::~GTexto()
{
    if (fuente != nullptr)
    {
        TTF_CloseFont(fuente);
        fuente = nullptr;
    }
}

/* INGRESOS */

void GTexto::ingTexto(std::string cad)
{
    texto = cad;
}

void GTexto::ingFuente(std::string nf)
{
    fuente = TTF_OpenFont(nf.c_str(), GConfig::tam_fuente);
    if (!fuente)
        std::cout << "No se ha podido cargar la fuente de texto: " << GConfig::nombre_fuente << std::endl;
}

void GTexto::ingTam(unsigned t)
{
    tam = t;
}

void GTexto::ingEstilo(int e)
{
    if (fuente != nullptr)
    {
        TTF_SetFontStyle(fuente, e);
    }
    // Talvez mostrar un error que aun no se ha creado TTF_Font
}

void GTexto::ingColor(SDL_Color c)
{
    color.r = c.r;
    color.g = c.g;
    color.b = c.b;
    color.a = c.a;
}

/*
void GTexto::ingPosicion(int x, int y)
{
    texto_espacio.x = x;
    texto_espacio.y = y;
}
*/

/* RETORNOS */

std::string GTexto::retTexto() const
{
    return texto;
}

TTF_Font *GTexto::retFuente() const
{
    return fuente;
}

EstiloFuente GTexto::retEstilo() const
{
    return estilo;
}

SDL_Color GTexto::retColor() const
{
    return color;
}

void GTexto::dibujar(GRenderizador *r)
{
    if (fuente == nullptr)
        return;
    SDL_Surface *superficie = nullptr;
    SDL_Texture *tex = nullptr;
    superficie = TTF_RenderText_Solid(fuente, texto.c_str(), color);
    if (superficie == nullptr)
        return;
    tex = SDL_CreateTextureFromSurface(r->retGrender(), superficie);
    ingTextura(tex);
    SDL_FreeSurface(superficie);
    SDL_Rect e = retEspacio();
    if (retTextura() == nullptr)
        return;
    SDL_QueryTexture(retTextura(), nullptr, nullptr, &e.w, &e.h);
    SDL_RenderCopy(r->retGrender(), retTextura(), nullptr, &e);
}

