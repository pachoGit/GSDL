#include "GConfig.h"

SDL_Rect GConfig::espacio_defecto = {0, 0, 30, 30};

/****** INFORMACION POR DEFECTO DEL MANEJO DE LA VENTANA PRINCIPAL ******/

string GConfig::titulo_ventana = "Mi ventana";
int GConfig::alto_ventana = 640;
int GConfig::ancho_ventana = 480;


/******          FIN DEL MANEJO DE LA VENTANA PRINCIAL             ******/

/****** INFORMACION POR DEFECTO DEL MANEJO DE FUENTE DE TEXTO ******/

//string GConfig::nombre_fuente = "prstartk.ttf";
string GConfig::nombre_fuente = "OpenSans-Regular.ttf";
string GConfig::path_fuente = "recursos/fuentes/open-sans/";
unsigned GConfig::tam_fuente = 10;
GColor GConfig::color_fuente = {0x00, 0x00, 0x00, 0x00};

/******                 FIN DEL MANEJO DE TEXTO               ******/

/* Informacion por defecto para los botones */

string GConfig::texto_boton = "Boton";
GColor GConfig::color_boton = {0xE1, 0xEB, 0xEF, 0xFF};
GColor GConfig::color_boton_mouse = {0x00, 0xEB, 0xFF, 0x64};

/* Cajas de entrada de texto */
//GColor GConfig::color_fondo_caja = GCColor::BLANCO;
//GColor GConfig::color_borde_caja = GCColor::ROJO; // Perimetro de la caja
//GColor GConfig::color_texto_caja = GCColor::NEGRO;

SDL_Rect GConfig::espacio_campo = {0, 0, 200,  20};
SDL_Rect GConfig::espacio_area  = {0, 0, 100, 60};
