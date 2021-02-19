/* Este archivo tiene toda la configuracion por defecto de las cosas en GSDL */

#ifndef GCONFIG_H
#define GCONFIG_H

#include <SDL2/SDL.h>
#include <string>
#include "Tipos.h"

using namespace std;

class GConfig
{
  public:

    // Espacio por defecto para una textura
    static SDL_Rect espacio_defecto;

    /****** INFORMACION POR DEFECTO DEL MANEJO DE LA VENTANA PRINCIPAL ******/
    
    static string titulo_ventana;

    static int alto_ventana;

    static int ancho_ventana;

    
    /******          FIN DEL MANEJO DE LA VENTANA PRINCIAL             ******/


    /****** INFORMACION POR DEFECTO DEL MANEJO DE FUENTE DE TEXTO ******/

    // Fuente por defecto de todos los textos
    static string nombre_fuente;

    // Ruta de la fuente de texto
    static string path_fuente;    

    // Tamanio de fuente por defecto de todos los textos
    static unsigned tam_fuente;

    // Color por defecto del texto - Negro
    static GColor color_fuente;

    /****** FIN DEL MANEJO DE TEXTO ******/

    /* Informacion por defecto para los botones */
    static string texto_boton;

    // El color del boton cuando esta sin eventos
    static GColor color_boton;

    // El color del boton cuando el mouse esta encima
    static GColor color_boton_mouse;
};

#endif /* GCONFIG_H */
