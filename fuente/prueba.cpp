#include <iostream>
#include "GSDL.h"
/*
#include "GVentana.h"
#include "elementos/GTexto.h"
*/

int main()
{
    GVentana ventana("prueba");
    GTexto texto("Aceptar");

    ventana.agregar(&texto);

    ventana.mostrar();

    return 0;
}
