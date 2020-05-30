# CrystalUI
Simple XML-based OpenGL UI system

## Usage
By far the easiest way to use CrystalUI within your project is to add a git submodule and then 
include it as a subdirectory in CMake:

```cmake
add_subdirectory(lib/CrystalUI)
target_include_directories(yourproject PRIVATE ... lib/CrystalUI/src lib/CrystalUI/inc)
target_link_libraries(yourproject ... CrystalUI)
```

## Examples
First, you have to register a GUI handler. This handles all the calls to your window and OpenGL loader:
```cpp
#include <crystal/CrystalUI.h>

class GuiHandler : public crystal::IGuiHandler {
public:
    void set_cursor(crystal::Cursor cursor) override;

    crystal::Texture *load_texture(const std::string &path) override;

    glm::vec2 get_viewport_size() override;
};
```

Then register the handler and initialize CrystalUI:
```cpp
crystal::CrystalUI::initialize(&guiHandler, "path/to/font/file");
```

> CrystalUI uses signed distance field font rendering. I recommend [Hiero](https://libgdx.badlogicgames.com/tools.html) for generating those files.

Also, make sure that you call the events:
```cpp
void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    crystal::CrystalUI::get_instance()->get_gui_renderer()->layout();
}
void character_callback(GLFWwindow *window, unsigned int codepoint) {
    crystal::CrystalUI::get_instance()->get_gui_renderer()->on_character_typed(codepoint);
}
```
and so on.

The required events are:
1. `GuiRenderer::on_mouse_down`
2. `GuiRenderer::on_mouse_up`
3. `GuiRenderer::on_mouse_move`
4. `GuiRenderer::on_character_typed`
5. `GuiRenderer::on_key_event`
6. `GuiRenderer::layout` (Call when you want to relayout, e.g. when the window size changes.)
6. `GuiRenderer::draw`  (Call in your render loop)

Then build a screen, which may look something like this:
```xml
<?xml version="1.0" encoding="UTF-8"?>
<!--
    Author: Twometer
    Date: 5/9/20 2:10 AM
-->

<Screen Id="menuScreen" VerticalAlignment="STRETCH"  HorizontalAlignment="STRETCH">
    <Panel Id="mainPanel" VerticalAlignment="CENTER" HorizontalAlignment="CENTER" Rows="5" Cols="1" Padding="32,16">
        <Label Id="titleLabel" Row="0" Text="Game of Life" FontSize="0.8" VerticalAlignment="CENTER"
               HorizontalAlignment="CENTER"/>
        <Label Id="subtitleLabel" Row="1" Text="(c) 2020 Twometer Apps" FontSize="0.25" VerticalAlignment="CENTER"
               HorizontalAlignment="CENTER" Margin="0,8"/>
        <Button Id="btnNewGame" Row="2" Text="New game" FontSize="0.55" Margin="32,8" Padding="32,0"
                HorizontalAlignment="STRETCH"/>
        <Button Id="btnLoadGame" Row="3" Text="Load game" FontSize="0.55" Margin="32,8" Padding="32,0"
                HorizontalAlignment="STRETCH"/>
        <Button Id="btnExitGame" Row="4" Text="Exit game" FontSize="0.55" Margin="32,8" Padding="32,0"
                HorizontalAlignment="STRETCH"/>
    </Panel>
</Screen>
```

```cpp
#include <crystal/base/Screen.h>
#include <crystal/io/XmlGuiLoader.h>

class MenuScreen : public crystal::Screen {

public:
    MenuScreen() : Screen("mainMenuScreen") {
        crystal::XmlGuiLoader::load(this, "main_menu.xml");
        
        auto btnNewGame = find_component<Button>("btnNewGame");
        auto btnLoadGame = find_component<Button>("btnLoadGame");
        auto btnExitGame = find_component<Button>("btnExitGame");
        
        btnNewGame->set_click_listener([]() {
            // Do something
        });
    }

};
```

And finally, display the screen:
```cpp
    crystal::CrystalUI::get_instance()->get_gui_renderer()->show_screen(new MenuScreen());
```
