cmake_minimum_required(VERSION 3.10)

project(libgsdl)
add_subdirectory(motor)
set(CMAKE_CXX_STANDARD 11)

set(MOTORLIB motor)

# Configuracion de SDL2
find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

set(GFUENTE GConfig.cpp GVentana.cpp)
set(GCABECERA GConfig.h GVentana.h)

add_executable(libgsdl prueba.cpp ${GFUENTE})

target_link_libraries(libgsdl ${SDL2_LIBRARIES} ${SDL2TTF_LIBRARY} ${MOTORLIB})


