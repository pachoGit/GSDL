#include <iostream>
#include "GSDL.h"

/*
#include "GVentana.h"
#include "elementos/GTexto.h"
*/

// Esta funcion se la va a pasar cuando encuentre el evento
void mostrar()
{
    std::cout << "Presione el click :D" << std::endl;
}

int main()
{
    // Iniciamos los modulos de SDL
    if (iniciarGSDL() != 0)
        return -1;
    
    GVentana ventana("prueba");
    GBoton aceptar(new GTexto("Aceptar"));
    GTexto texto2("Bueno comenzamos a experimentar", 30);
    GBoton cancelar(new GTexto("Cancelar"));

    texto2.ingPosicion(100, 100);
    texto2.ingColor({0x00, 0xFF, 0x121, 0x255});

    aceptar.ingPosicion(100, 30);
    cancelar.ingPosicion(30, 30);

    ventana.agregar(&aceptar);
    ventana.agregar(&texto2);
    ventana.agregar(&cancelar);

    cancelar.agregarEvento("click", &mostrar);

    ventana.mostrar();

    cerrarGSDL();

    return 0;
}
