cmake_minimum_required(VERSION 3.10)
project(libgsdl)

# set(CMAKE_CXX_STANDARD 11)

add_subdirectory(motor)
add_subdirectory(elementos)

set(GFUENTES GConfig.cpp GVentana.cpp)
set(GCABECERAS GConfig.h GVentana.h GSDL.h)

# Librerias
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
find_package(SDL2_ttf REQUIRED)

set(LIBMOTOR motor)
set(LIBELEMENTOS elementos)

add_executable(libgsdl ${GFUENTES} prueba.cpp)

target_link_libraries(libgsdl ${SDL2_LIBRARIES} ${LIBMOTOR} ${LIBELEMENTOS} SDL2::TTF)


