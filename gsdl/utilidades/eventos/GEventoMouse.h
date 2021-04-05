#ifndef GEVENTOMOUSE_H
#define GEVENTOMOUSE_H

class GEventoMouse
{
  public:

    GEventoMouse()
    {
    }

    ~GEventoMouse()
    {
    }
    
    void retPosicionMouse(int *x, int *y)
    {
        SDL_GetMouseState(x, y);
    }

    
};

#endif /* GEVENTOMOUSE_H */
