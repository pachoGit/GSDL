#include "GMotor.h"

GMotor::GMotor()
{
    grenderizador = nullptr;
}

GMotor &GMotor::retGMotor()
{
    static GMotor motor;
    return motor;
}

GRenderizador *GMotor::retGRenderizador() const
{
    return grenderizador;
}

void GMotor::iniciarModulos()
{
    grenderizador = new GRenderizador;
}

void GMotor::destruirModulos()
{
    delete grenderizador;
    grenderizador = nullptr;
}

