#pragma once

#include "stdafx.h"

#include <glm/glm.hpp>

/**
 * Player class
 */
class Player {
public:
    /**
     * Directions enum.
     */
    enum Direction {
        kForward,
        kBackward,
        kLeft,
        kRight
    };

    // public functions

    void ProcessKeyboard(const Direction direction, const float delta_time);

    // getters and setters
    glm::vec3 GetPosition() { return position_; }
    void SetHorizontalAngle(const float angle) { horizontal_angle_ = angle; }

private:
    // private variables
    float movement_speed_ = 2.5f;
    glm::vec3 position_ = glm::vec3(0.0f, 0.5f, 0.0f);
    float horizontal_angle_ = 0.0f;
};
