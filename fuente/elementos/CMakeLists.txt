cmake_minimum_required(VERSION 3.10)

project(elementos)

# set(CMAKE_CXX_STANDARD 11)

set(ELEMENTO_FUENTE GTexto.cpp GBoton.cpp)
set(ELEMENTO_CABECERAS GTexto.h GBoton.h GElemento.h)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
find_package(SDL2_ttf REQUIRED)


add_library(elementos ${ELEMENTO_FUENTE})

