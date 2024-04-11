#pragma once

#include "stdafx.h"
#include <cstdlib>
#include "player.h"
#include "enemy_cube.h"

/**
 * Models class.
 */
class Models {
public:
    /**
     * Enum with different model groups.
     */
    enum ModelGroupName {
        kFloor,
        kPlayer,
        kCube,
        kNumModelGroups
    };

    /**
     * ModelGroup data structure.
     */
    struct ModelGroup {

        const float * vertices_;
        const int vertices_size_;
        const int num_vertices_;

        // these need to be manually initialized after the constructor
        int num_models_ = 0;
        glm::vec3 * positions_ = nullptr;

        ModelGroup(const float * vertices, const int vertices_size, const int num_vertices);
        ~ModelGroup();
    };

    // constructor and destructor
    Models(Player * player_ptr, std::vector<EnemyCube> * enemy_cubes_ptr);

    // public functions

    void Update(const float delta_time);

    const float * GetVertices(const int model_group_i);
    const int GetVerticesSize(const int model_group_i);
    const int GetNumVertices(const int model_group_i);
    const int GetNumModels(const int model_group_i);

    glm::vec3 * GetPositions(const int model_group_i);

private:
    // private variables

    Player * player_ptr_;
    std::vector<EnemyCube> * enemy_cubes_ptr_;

    std::array<ModelGroup, kNumModelGroups> model_groups_;
};
