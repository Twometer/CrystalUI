//
// Created by twome on 08/05/2020.
//

#include "Panel.h"

namespace crystal {
    void Panel::draw(Graphics &graphics) {
        graphics.begin();
        graphics.push_rectangle(position.x, position.y, size.x, size.y, glm::vec3(0.1843, 0.2218, 0.2431));
        graphics.push_rectangle(position.x, position.y, size.x, 2, glm::vec3(0.0, 0.6588, 1.0));
        graphics.end();

        Graphics g = graphics.create_offset(glm::vec2(0, 1));
        Container::draw(g);
    }

    Panel::Panel(const std::string &id) : Container(id) {

    }
}