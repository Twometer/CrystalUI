cmake_minimum_required(VERSION 3.16)
project(CrystalUI)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(libs/glm/glm)

add_library(CrystalUI
        ext/glad.cpp
        ext/spng.c
        ext/tinyxml2.cpp
        library.cpp
        library.h src/gl/Vao.cpp src/gl/Vao.h src/gl/MeshBuilder.cpp src/gl/MeshBuilder.h)

target_include_directories(CrystalUI PRIVATE libs/glm inc)