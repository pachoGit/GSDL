cmake_minimum_required(VERSION 3.10)
project(prueba)

# set(CMAKE_CXX_STANDARD 11)

set(GSDL_CODIGO_DIR ${CMAKE_CURRENT_SOURCE_DIR}/codigo})
set(GSDL_BINARIO_DIR ${CMAKE_CURRENT_BINARY_DIR}/producto})

add_subdirectory(gsdl)
set(LIBGSDL gsdl)

# Librerias
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${GSDL_CODIGO_DIR})

add_executable(prueba prueba.cpp)

target_link_libraries(prueba ${LIBGSDL})


