#include <iostream>
#include "GSDL.h"

// Esta funcion se la va a pasar cuando encuentre el evento
void saludar()
{
    std::cout << "Hola Buenos dias :D" << std::endl;
}

void despedir()
{
    std::cout << "Adios!... muchas gracias :D" << std::endl;
}

int main()
{
    // Iniciamos los modulos de SDL
    if (iniciarGSDL() != 0)
        return -1;
    
    GVentana ventana("prueba");
    GBoton aceptar(new GTexto("Aceptar"));
    GBoton cancelar(new GTexto("Cancelar"));
    
    aceptar.ingPosicion(100, 30);
    cancelar.ingPosicion(30, 30);

    ventana.agregar(&aceptar);
    ventana.agregar(&cancelar);

    cancelar.agregarEvento("click", &saludar);


    GDesplegable submenu(new GBoton("Mi lista depegable"));
    submenu.ingPosicion(10, 200);
    submenu.agregar(new GBoton("Hola"));
    submenu.agregar(new GBoton("Buenas"));
    submenu.agregar(new GBoton("Vaya Menu"));
    ventana.agregar(&submenu);


    GTexto tex("Hola buenos dias :D");
    tex.ingColor(GCColor::deHexa("#0D729A"));
    ventana.agregar(&tex);

    ventana.mostrar();

    return 0;
}
