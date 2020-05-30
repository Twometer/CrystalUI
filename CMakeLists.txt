cmake_minimum_required(VERSION 3.16)
project(CrystalUI)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(libs/glm/glm)

add_library(CrystalUI
        ext/glad.cpp
        ext/spng.c
        ext/tinyxml2.cpp
        src/crystal/gl/Vao.cpp
        src/crystal/gl/MeshBuilder.cpp
        src/crystal/shaders/IShader.cpp
        src/crystal/font/FontRenderer.cpp
        src/crystal/io/XmlGuiLoader.cpp
        src/crystal/io/FontLoader.cpp
        src/crystal/base/Container.cpp
        src/crystal/base/Screen.cpp
        src/crystal/base/Dialog.cpp
        src/crystal/base/Component.cpp
        src/crystal/base/ImageComponent.cpp
        src/crystal/components/Label.cpp
        src/crystal/components/Panel.cpp
        src/crystal/components/Button.cpp
        src/crystal/components/TextBox.cpp
        src/crystal/components/CheckBox.cpp
        src/crystal/components/ToolButton.cpp
        src/crystal/GuiRenderer.cpp
        src/crystal/Graphics.cpp
        src/crystal/CrystalUI.cpp)

target_include_directories(CrystalUI PRIVATE libs/glm inc)