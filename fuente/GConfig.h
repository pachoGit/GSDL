/* Este archivo tiene toda la configuracion por defecto de las cosas en GSDL */

#ifndef GCONFIG_H
#define GCONFIG_H

#include <SDL2/SDL.h>
#include <string>

using namespace std;

class GConfig
{
  public:

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
    static SDL_Color color_fuente;

    /****** FIN DEL MANEJO DE TEXTO ******/

};

#endif /* GCONFIG_H */
