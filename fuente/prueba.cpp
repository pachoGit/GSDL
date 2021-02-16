#include <iostream>
#include "GSDL.h"

/*
#include "GVentana.h"
#include "elementos/GTexto.h"
*/

int main()
{
    // Iniciamos los modulos de SDL
    if (iniciarGSDL() != 0)
        return -1;
    
    GVentana ventana("prueba");
    GTexto texto("Aceptar");
    GTexto texto2("Bueno comenzamos a experimentar", 30);

    texto2.ingPosicion(100, 100);
    texto2.ingColor({0x00, 0xFF, 0x121, 0x255});

    ventana.agregar(&texto);
    ventana.agregar(&texto2);

    ventana.mostrar();

    cerrarGSDL();

    return 0;
}
