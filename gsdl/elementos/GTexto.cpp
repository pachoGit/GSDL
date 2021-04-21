#include "GTexto.h"

GTexto::GTexto() : GElemento()
{
    texto = "Texto";
    nombre_fuente = GConfig::nombre_fuente;
    tam = GConfig::tam_fuente;
    /* Color por defecto - negro */
    color = GConfig::color_fuente;
    estilo = GNORMAL;
    ttf_fuente = nullptr;
}

GTexto::GTexto(std::string cad) : GElemento()
{
    texto = cad;
    nombre_fuente = GConfig::nombre_fuente;
    tam = GConfig::tam_fuente;
    /* Color por defecto - negro */
    color = GConfig::color_fuente;
    estilo = GNORMAL;
    ttf_fuente = nullptr;
}

GTexto::GTexto(std::string cad, unsigned t) : GElemento()
{
    texto = cad;
    nombre_fuente = GConfig::nombre_fuente;
    tam = t;
    /* Color por defecto - negro */
    color = GConfig::color_fuente;
    estilo = GNORMAL;
    ttf_fuente = nullptr;
}

GTexto::~GTexto()
{
    if (ttf_fuente != nullptr)
    {
        TTF_CloseFont(ttf_fuente);
        ttf_fuente = nullptr;
    }
}

/* INGRESOS */

void GTexto::ingTexto(std::string cad)
{
    texto = cad;
}

void GTexto::ingNombreFuente(std::string nf)
{
    nombre_fuente = nf;
}

void GTexto::ingTam(unsigned t)
{
    tam = t;
}

void GTexto::ingColor(GColor c)
{
    color = c;
}

void GTexto::ingEstilo(EstiloFuente e)
{
    estilo = e;
}

void GTexto::ingTTFFuente(TTF_Font *f)
{
    ttf_fuente = f;
}

/* RETORNOS */

std::string GTexto::retTexto() const
{
    return texto;
}

std::string GTexto::retNombreFuente() const
{
    return nombre_fuente;
}

GColor GTexto::retColor() const
{
    return color;
}

EstiloFuente GTexto::retEstilo() const
{
    return estilo;
}

void GTexto::construir(GRenderizador *r)
{
    if (!ttf_fuente) // Si ya esta cargado, no cargar otra TTF_Font
    {
        ttf_fuente = TTF_OpenFont(nombre_fuente.c_str(), tam);
        if (!ttf_fuente) // No se pudo cargar la fuente de texto
        {
            // TODO: Debemos implementar una mejor forma para el informe de errores
            std::cout << "No se ha cargado la fuente: " << nombre_fuente << std::endl;
            return;
        }
    }
    SDL_Color c = {color.at(0), color.at(1), color.at(2), color.at(3)};
    SDL_Surface *temp = TTF_RenderUTF8_Solid(ttf_fuente, texto.c_str(), c);
    if (!temp)
        return;
    SDL_Texture *textura = SDL_CreateTextureFromSurface(r->retGrender(), temp);
    if (!textura)
        return;
    ingTextura(textura);
    SDL_FreeSurface(temp);
    int ancho, alto;
    SDL_QueryTexture(textura, nullptr, nullptr, &ancho, &alto);
    ingArea(ancho, alto);
}

// No hay evento que hacer
void GTexto::controlarEvento(SDL_Event *e)
{
    GEscuchadorMouse *em = retGEscuchadorMouse();
    if (!em)
        return;
    // Para eventos del mouse verificamos si el mouse esta encima del elemento
    int x, y;
    SDL_GetMouseState(&x, &y);
    if (!estaAqui(x, y))
        return;
    if (e->type == SDL_MOUSEBUTTONDOWN && e->button.button == SDL_BUTTON_LEFT)
        em->clickIzquierdo(new GEventoMouse());
    else if (e->type == SDL_MOUSEBUTTONDOWN && e->button.button == SDL_BUTTON_RIGHT)
        em->clickDerecho(new GEventoMouse());
    
}

void GTexto::dibujar(GRenderizador *r)
{
    if (!retTextura())
        return;
    SDL_Rect e = retEspacio();
    SDL_RenderCopy(r->retGrender(), retTextura(), nullptr, &e);
}

