#pragma once

#include "stdafx.h"
#include "world_object.h"

/**
 * Player class
 */
class Player : public WorldObject {
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

    // constructor
    explicit Player(const glm::vec3 & position) : WorldObject(position) {}

    // public functions

    void ProcessKeyboard(const Direction direction, const float delta_time);

    // getters and setters
    void SetHorizontalAngle(const float angle) { horizontal_angle_ = angle; }

private:
    // private variables
    float movement_speed_ = 2.5f;
    float horizontal_angle_ = 0.0f;
};
