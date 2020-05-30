//
// Created by twome on 06/05/2020.
//

#ifndef CRYSTALUI_ANIMATED_H
#define CRYSTALUI_ANIMATED_H

#include <glm/glm.hpp>

constexpr float ANIMATION_SPEED = 0.045f;

class Animated {
private:
    float srcValue;
    float curValue;
    float dstValue;

    float progress;

public:
    Animated(float value) {
        this->srcValue = value;
        this->dstValue = value;
        this->curValue = value;
    }

    void set_value(float value) {
        dstValue = value;
    }

    float get_value() const {
        return curValue;
    }

    void update() {
        if (progress < 1.0f)
            progress += ANIMATION_SPEED;
        curValue = srcValue + (dstValue - srcValue) * glm::sin(progress * M_PI_2);
    }

    void clamp_to(float min, float max) {
        dstValue = glm::clamp(dstValue, min, max);
    }

    Animated &operator=(const float other) {
        set_value(other);
        reset();
        return *this;
    }

    Animated &operator+=(const float other) {
        this->dstValue += other;
        reset();
        return *this;
    }

    Animated &operator-=(const float other) {
        this->dstValue -= other;
        reset();
        return *this;
    }

private:
    void reset() {
        progress = 0.0f;
        srcValue = curValue;
    }

};

#endif //CRYSTALUI_ANIMATED_H
