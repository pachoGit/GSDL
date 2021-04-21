cmake_minimum_required(VERSION 3.10)
project(gsdl)

add_subdirectory(motor)
add_subdirectory(elementos)
add_subdirectory(utilidades)

set(GFUENTES
  GConfig.cpp
  GVentana.cpp
  )

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/motor)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#set(GCABECERAS
#  GConfig.h
#  GVentana.h
#  Tipos.h
#  GSDL.h)

# Librerias
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/motor/extra-sdl)
find_package(SDL2_ttf REQUIRED)

set(LIBMOTOR motor)
set(LIBELEMENTOS elementos)
set(LIBUTILIDADES utilidades)

# Modo debuger
#set(CMAKE_BUILD_TYPE Debug)

add_library(gsdl ${GFUENTES})

target_link_libraries(gsdl
  ${SDL2_LIBRARIES}
  ${LIBMOTOR}
  ${LIBELEMENTOS}
  ${LIBUTILIDADES}
  SDL2::TTF)
