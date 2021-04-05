#ifndef GMOTOR_H
#define GMOTOR_H

#include "GRenderizador.h"

class GMotor
{
  private:
    
    GRenderizador *grenderizador;

  public:

    GMotor();

    // Retorna una instancia estatica del objeto GMotor
    // El motor puede estar disponible desde cualquier modulo utilizando solo el espacio
    // de nombres y no el indicador
    static GMotor &retGMotor();

    // Retorna el objeto de renderizado
    GRenderizador *retGRenderizador() const;

    // Iniciar los modulos internos del motor
    void iniciarModulos();
    
    // Destruir los modulos internos del motor
    void destruirModulos();

};


#endif /* GMOTOR_H */
