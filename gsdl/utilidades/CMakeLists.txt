cmake_minimum_required(VERSION 3.10)

project(utilidades)

set(UTILIDADES_FUENTE
  GCColor.cpp
  )
set(UTILIDADES_CABECERAS
  GCColor.h
  ../Tipos.h
  )

add_library(utilidades ${UTILIDADES_FUENTE})
