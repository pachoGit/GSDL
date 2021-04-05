// Simple implementacion de una clase para el manejo de los colores para GSDL

#ifndef GCCOLOR_H
#define GCCOLOR_H

#include "../Tipos.h"
#include <string>

class GCColor
{
  public:

    // Lista de colores predeterminados
    static GColor NEGRO;

    static GColor BLANCO;

    static GColor ROJO;

    static GColor VERDE;

    static GColor AZUL; 

    static GColor PLATA;  

    static GColor GRIS;   

    static GColor MARRON;

    static GColor OLIVA;

    static GColor LIMA; 

    static GColor AQUA;  

    static GColor FUCSIA;

    static GColor PURPURA;

    // Obtener el color a travez de codigo hexadecimal
    // Formatos correctos:
    // "#FF00FF" o "#FF00FF00"
    // es decir si tambien desea colocar la opacidad
    static GColor deHexa(std::string codigo);

  private:
    
    // El codigo hexadecimal es correcto?
    static bool esCorrecto(std::string codigo);

    // Convierte en entero dos caracteres hexadecimales
    static unsigned parHexaADecimal(std::string dos);

};


#endif /* GCCOLOR_H */
