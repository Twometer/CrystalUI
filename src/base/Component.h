//
// Created by twome on 08/05/2020.
//

#ifndef CRYSTALUI_COMPONENT_H
#define CRYSTALUI_COMPONENT_H

#include <string>
#include <glm/vec2.hpp>
#include <functional>
#include "../enums/Alignment.h"
#include "../enums/Cursor.h"
#include "../Graphics.h"

/**
 * The base class for all GUI components
 */
class Component {
protected:
    std::string id;

    int row = 0;
    int rowSpan = 1;
    int column = 0;
    int columnSpan = 1;

    glm::vec2 position = glm::vec2(0, 0);

    glm::vec2 minimumSize = glm::vec2(0, 0);
    glm::vec2 maximumSize = glm::vec2(0, 0);
    glm::vec2 size = glm::vec2(0, 0);

    glm::vec2 margin = glm::vec2(8, 8);
    glm::vec2 padding = glm::vec2(0, 0);

    Alignment verticalAlignment = Alignment::START;
    Alignment horizontalAlignment = Alignment::START;

private:
    bool isMouseDown = false;
    bool isMouseOver = false;
    bool isFocused = false;

    std::function<void()> clickListener;

public:
    explicit Component(const std::string &id);

    virtual void draw(Graphics &graphics) = 0;

    virtual void layout() = 0;

    // Properties //
    const std::string &get_id() const;

    void set_row(int r);

    int get_row() const;

    void set_row_span(int rowSpan);

    int get_row_span() const;

    void set_col(int c);

    int get_col() const;

    void set_col_span(int colSpan);

    int get_col_span() const;

    void set_position(glm::vec2 position);

    glm::vec2 get_position() const;

    glm::vec2 get_minimum_size() const;

    void set_maximum_size(glm::vec2 maxSize);

    glm::vec2 get_maximum_size() const;

    void set_size(glm::vec2 size);

    glm::vec2 get_size() const;

    void set_margin(glm::vec2 margin);

    glm::vec2 get_margin() const;

    void set_padding(glm::vec2 padding);

    void set_vertical_alignment(Alignment verticalAlignment);

    Alignment get_vertical_alignment() const;

    void set_horizontal_alignment(Alignment horizontalAlignment);

    Alignment get_horizontal_alignment() const;

    virtual Cursor get_cursor();

    // Mouse state //
    bool is_inside(glm::vec2 position) const;

    bool is_mouse_over() const;

    bool is_mouse_down() const;

    bool is_focused() const;

    // Event handlers //
    void set_click_listener(std::function<void()> listener);

    // Events //
    virtual void on_mouse_down(glm::vec2 position);

    virtual void on_mouse_up(glm::vec2 position);

    virtual void on_click(glm::vec2 position);

    virtual void on_mouse_move(glm::vec2 position);

    virtual void on_mouse_enter();

    virtual void on_mouse_leave();

    virtual void on_got_focus();

    virtual void on_lost_focus();

    virtual void on_character_typed(uint32_t codepoint);

    virtual void on_key_event(int key, int action);

};

#endif //CRYSTALUI_COMPONENT_H
