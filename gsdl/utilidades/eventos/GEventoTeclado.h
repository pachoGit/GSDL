#ifndef GEVENTOTECLADO_H
#define GEVENTOTECLADO_H

class GEventoTeclado
{
  public:

    GEventoTeclado()
    {
    }

    ~GEventoTeclado()
    {
    }

    /* Retorna el nombre de la tecla presionada. Los nombres tienen la forma de la funcion
     * SDL_GetKeyName por lo que lea https://wiki.libsdl.org/SDL_Keycode para saber como 
     * retorna el nombre de dicha tecla
     */
    /*
    const char *retTecla()
    {
        SDL_Event *e = retGestorEvento();
        if (e->type == SDL_KEYDOWN)
        {
            return SDL_GetKeyName(e->key.keysym.sym);
        }
        return nullptr;
    }
    */
};


#endif /* GEVENTOTECLADO_H */
