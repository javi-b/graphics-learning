#pragma once

#include "stdafx.h"
#include "world_object.h"

/**
 * EnemyCube class.
 */
class EnemyCube : public WorldObject {
public:
    // constructor
    explicit EnemyCube(const glm::vec3 & position) : WorldObject(position){};

private:
};
