#include "GConfig.h"

SDL_Rect GConfig::espacio_defecto = {0, 0, 30, 30};

/****** INFORMACION POR DEFECTO DEL MANEJO DE LA VENTANA PRINCIPAL ******/

string GConfig::titulo_ventana = "Mi ventana";
int GConfig::alto_ventana = 640;
int GConfig::ancho_ventana = 480;


/******          FIN DEL MANEJO DE LA VENTANA PRINCIAL             ******/

/****** INFORMACION POR DEFECTO DEL MANEJO DE FUENTE DE TEXTO ******/

string GConfig::nombre_fuente = "prstartk.ttf";
string GConfig::path_fuente = "recursos/fuentes/open-sans/";
unsigned GConfig::tam_fuente = 10;
SDL_Color GConfig::color_fuente = {0x00, 0x00, 0x00, 0x00};

/******                 FIN DEL MANEJO DE TEXTO               ******/
