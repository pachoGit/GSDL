#include "GCColor.h"
#include <iostream>
#include <map>

GColor GCColor::NEGRO    = {0x00, 0x00, 0x00, 0xFF};
GColor GCColor::BLANCO   = {0xFF, 0xFF, 0xFF, 0xFF};
GColor GCColor::ROJO     = {0xFF, 0x00, 0x00, 0xFF};
GColor GCColor::VERDE    = {0x00, 0xFF, 0x00, 0xFF};
GColor GCColor::AZUL     = {0x00, 0x00, 0xFF, 0xFF};
GColor GCColor::PLATA    = {0xC0, 0xC0, 0xC0, 0xFF};
GColor GCColor::GRIS     = {0x80, 0x80, 0x80, 0xFF};
GColor GCColor::MARRON   = {0x80, 0x00, 0x00, 0xFF};
GColor GCColor::OLIVA    = {0x80, 0x80, 0x00, 0xFF};
GColor GCColor::LIMA     = {0x00, 0xFF, 0x00, 0xFF};
GColor GCColor::AQUA     = {0x00, 0xFF, 0xFF, 0xFF};
GColor GCColor::FUCSIA   = {0xFF, 0x00, 0xFF, 0xFF};
GColor GCColor::PURPURA  = {0x80, 0x00, 0x80, 0xFF};

// Tabla con los valores de los caracteres hexadecimales
static const std::map<unsigned char, unsigned int> tabla = {
    {'0', 0 }, {'1', 1 }, {'2', 2 }, {'3', 3 },
    {'4', 4 }, {'5', 5 }, {'6', 6 }, {'7', 7 },
    {'8', 8 }, {'9', 9 }, {'A', 10}, {'B', 11},
    {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15},
};


GColor GCColor::deHexa(std::string codigo)
{
    if (esCorrecto(codigo) == false)
    {
        std::cout << "Mal codigo de color en hexadecimal: " << codigo << std::endl;
        return BLANCO; // TODO: O que cosa enviamos?
    }
    
    // Eliminamos el '#'
    codigo.erase(0, 1);

    GColor color; // Color final formado
    int icolor = 0;
    std::string sub; // Dos caracteres del codigo

    for (auto i = codigo.begin(); i != codigo.end(); i+=2)
    {
        sub.push_back(*i);
        sub.push_back(*(i+1));
        color.at(icolor++) = parHexaADecimal(sub);
        sub = "";
    }
    if (icolor == 3) // No ingreso opacidad
        color.at(icolor) = 0xFF; // Por defecto, bien claro
    return color;
}

bool GCColor::esCorrecto(std::string codigo)
{
    if (codigo.length() != 7 && codigo.length() != 9)
        return false;
    if (codigo.at(0) != '#')
        return false;
    codigo.erase(0, 1); // Eliminamos el '#'
    for (auto caracter : codigo)
    {
        if (caracter < '0' || caracter > 'F')
            return false;
    }
    return true;
}

unsigned GCColor::parHexaADecimal(std::string dos)
{
    unsigned v0 = tabla.at(dos.at(0));
    unsigned v1 = tabla.at(dos.at(1));

    // v0 * (16^1) + v1 * (16^0)
    return v0 * 16 + v1 * 1;
}
