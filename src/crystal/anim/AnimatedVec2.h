//
// Created by twome on 09/05/2020.
//

#ifndef CRYSTALUI_ANIMATEDVEC2_H
#define CRYSTALUI_ANIMATEDVEC2_H

#include "Animated.h"

namespace crystal {
    class AnimatedVec2 {
    private:
        Animated x;
        Animated y;

    public:
        AnimatedVec2(glm::vec2 defaultValue) : x(defaultValue.x), y(defaultValue.y) {
        }

        AnimatedVec2 &operator=(const glm::vec2 value) {
            x = value.x;
            y = value.y;
            return *this;
        }

        AnimatedVec2 &operator+=(const glm::vec2 value) {
            x += value.x;
            y += value.y;
            return *this;
        }

        glm::vec2 get_value() const {
            return glm::vec2(x.get_value(), y.get_value());
        }

        void update() {
            x.update();
            y.update();
        }

    };
};
#endif //CRYSTALUI_ANIMATEDVEC2_H
