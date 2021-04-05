/* Este archivo tiene toda la configuracion por defecto de las cosas en GSDL */

#ifndef GCONFIG_H
#define GCONFIG_H

#include <SDL2/SDL.h>
#include <string>
#include "Tipos.h"
#include "utilidades/GCColor.h"

using namespace std;

class GConfig
{
  public:

    /* TEXTURA POR DEFECTO  */

    //static SDL_Texture *textura_defecto;

    // Espacio por defecto para una textura
    static SDL_Rect espacio_defecto;

    /* FIN TEXTURA */
    

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

    /****** Informacion por defecto para los botones ******/
    static string texto_boton;

    // El color del boton cuando esta sin eventos
    static GColor color_boton;

    // El color del boton cuando el mouse esta encima
    static GColor color_boton_mouse;

    /****** Fin de los botones ******/

    /***** Cosas por defecto para las cajas de texto ******/

    // Color de fondo
    static GColor color_fondo_caja;

    // Color del texto
    static GColor color_texto_caja;

    // Perimetro de la caja
    static GColor color_borde_caja;

    /** Para Campo de texto **/
    
    static SDL_Rect espacio_campo;

    /** Para Area de texto **/

    static SDL_Rect espacio_area;

    /***** Fin de las cajas de texto ******/
};

#endif /* GCONFIG_H */
