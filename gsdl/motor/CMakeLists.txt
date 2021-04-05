cmake_minimum_required(VERSION 3.10)

project(motor)

# set(CMAKE_CXX_STANDARD 11)

set(MOTOR_FUENTE
  GRenderizador.cpp
  GMotor.cpp
  )

set(MOTOR_CABECERAS
  GRenderizador.h
  GMotor.h
  )

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/extra-sdl)
find_package(SDL2_ttf REQUIRED)

add_library(motor ${MOTOR_FUENTE})


