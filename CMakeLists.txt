cmake_minimum_required(VERSION 3.16)
project(CrystalUI)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(libs/glm/glm)

add_library(CrystalUI
        ext/glad.cpp
        ext/spng.c
        ext/tinyxml2.cpp
        src/gl/Vao.cpp
        src/gl/MeshBuilder.cpp
        src/shaders/IShader.cpp
        src/font/FontRenderer.cpp
        src/io/XmlGuiLoader.cpp
        src/io/FontLoader.cpp
        src/base/Container.cpp
        src/base/Screen.cpp
        src/base/Dialog.cpp
        src/base/Component.cpp
        src/base/ImageComponent.cpp
        src/components/Label.cpp
        src/components/Panel.cpp
        src/components/Button.cpp
        src/components/TextBox.cpp
        src/components/CheckBox.cpp
        src/components/ToolButton.cpp
        src/GuiRenderer.cpp
        src/Graphics.cpp
        src/CrystalUI.cpp)

target_include_directories(CrystalUI PRIVATE libs/glm inc)