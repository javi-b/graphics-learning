#pragma once

#include "stdafx.h"

#include <cstdlib>
#include <glm/glm.hpp>

#include "player.h"

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
        const int num_models_;
        glm::vec3 * positions_;

        ModelGroup(const float * vertices, const int vertices_size, const int num_vertices, const int num_models,
                const glm::vec3 * initial_positions);
    };

    // constructor
    explicit Models(Player * player_ptr);

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
    std::array<ModelGroup, kNumModelGroups> model_groups_;
};
