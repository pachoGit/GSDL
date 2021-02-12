#include "GTexto.h"
#include <iostream>

GTexto::GTexto()
{
    texto = "Texto";
    fuente = TTF_OpenFont(GConfig::nombre_fuente.c_str(), GConfig::tam_fuente);
    if (!fuente)
        std::cout << "No se ha podido cargar la fuente de texto: " << GConfig::nombre_fuente << std::endl;
    tam = GConfig::tam_fuente;
}

GTexto::GTexto(std::string cad)
{
    texto = cad;
    fuente = TTF_OpenFont(GConfig::nombre_fuente.c_str(), GConfig::tam_fuente);
    if (!fuente)
        std::cout << "No se ha podido cargar la fuente de texto: " << GConfig::nombre_fuente << std::endl;
    tam = GConfig::tam_fuente;
}

GTexto::GTexto(std::string cad, unsigned t)
{
    texto = cad;
    fuente = TTF_OpenFont(GConfig::nombre_fuente.c_str(), GConfig::tam_fuente);
    if (!fuente)
        std::cout << "No se ha podido cargar la fuente de texto: " << GConfig::nombre_fuente << std::endl;
    tam = t;
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
}

GTexto::~GTexto()
{
    TTF_CloseFont(fuente);
    fuente = nullptr;
}

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

std::string GTexto::retTexto() const
{
    return texto;
}



