#pragma once

#include "stdafx.h"

/**
 * WorldObject class.
 */
class WorldObject {
public:
    // constructor
    explicit WorldObject(const glm::vec3 & position) : position_(position){};

    // public functions

    // getters and setters
    glm::vec3 GetPosition() { return position_; }

protected:
    // protected variables
    glm::vec3 position_;
};
