#include <iostream>
#include "gsdl/GSDL.h"

class MiEvento : public GEscuchadorMouse
{
    void clickIzquierdo(GEventoMouse *e)
    {
        int x, y;
        e->retPosicionMouse(&x, &y);
        std::cout << "Click izquierdo en --> X: " << x << " Y: " << y << std::endl;
    }

    void clickDerecho(GEventoMouse *e)
    {
        std::cout << "Click Derecho..." << std::endl;
    }

    void izqPulsado(GEventoMouse *e)
    {
    }

    void derPulsado(GEventoMouse *e)
    {
    }
};
    

int main()
{
    GVentana ventana("prueba");
    ventana.ingTipoVentana(GVENTANA_CAMBIANTE);

    std::string titulo = "otro";
    GTexto texto(titulo, 20);
    texto.ingColor(GCColor::PURPURA);
    texto.ingEstilo(GNEGRITA); // Depende si el archivo ttf tiene incluido
    texto.ingPosicion(100, 100);

    MiEvento mi_evento;
    texto.agregarEscuchadorMouse(&mi_evento);

    ventana.agregar(&texto);

    GConfig::nombre_fuente = "OpenSans-Regular.ttf";
    //titulo = "Hola amigo :D";
    GTexto saludo(std::string("Persona"), 15);
    saludo.ingColor(GCColor::ROJO);

    ventana.agregar(&saludo);

    //GVentana ventana("prueba", 1000, 700);
    /*
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

    GCampoTexto campo;
    campo.ingPosicion(250, 250);
    ventana.agregar(&campo);

    */


    ventana.mostrar();

    return 0;
}
