#include "models.h"

// clang-format off

// floor

static const float kFloorVertices[] = {
    -100.0f, 0.0f, -100.0f, 0.0f, 0.0f, // triangle 1
     100.0f, 0.0f, -100.0f, 0.0f, 0.0f,
     100.0f, 0.0f,  100.0f, 0.0f, 0.0f,
     100.0f, 0.0f,  100.0f, 0.0f, 0.0f, // triangle 2
    -100.0f, 0.0f,  100.0f, 0.0f, 0.0f,
    -100.0f, 0.0f, -100.0f, 0.0f, 0.0f
};
static const int kFloorNumVertices = 6;
static Models::ModelGroup kFloorsModelGroup(kFloorVertices, sizeof(kFloorVertices), kFloorNumVertices);

// player

static const float kPlayerVertices[] = {
    // face 1
    -0.25f, -0.5f, -0.25f,  0.0f, 0.0f, // triangle 1
     0.25f, -0.5f, -0.25f,  1.0f, 0.0f,
     0.25f,  0.5f, -0.25f,  1.0f, 1.0f,
     0.25f,  0.5f, -0.25f,  1.0f, 1.0f, // triangle 2
    -0.25f,  0.5f, -0.25f,  0.0f, 1.0f,
    -0.25f, -0.5f, -0.25f,  0.0f, 0.0f,
    // face 2
    -0.25f, -0.5f,  0.25f,  0.0f, 0.0f, // triangle 1
     0.25f, -0.5f,  0.25f,  1.0f, 0.0f,
     0.25f,  0.5f,  0.25f,  1.0f, 1.0f,
     0.25f,  0.5f,  0.25f,  1.0f, 1.0f, // triangle 2
    -0.25f,  0.5f,  0.25f,  0.0f, 1.0f,
    -0.25f, -0.5f,  0.25f,  0.0f, 0.0f,
    // face 3
    -0.25f,  0.5f,  0.25f,  1.0f, 0.0f, // triangle 1
    -0.25f,  0.5f, -0.25f,  1.0f, 1.0f,
    -0.25f, -0.5f, -0.25f,  0.0f, 1.0f,
    -0.25f, -0.5f, -0.25f,  0.0f, 1.0f, // triangle 2
    -0.25f, -0.5f,  0.25f,  0.0f, 0.0f,
    -0.25f,  0.5f,  0.25f,  1.0f, 0.0f,
    // face 4
     0.25f,  0.5f,  0.25f,  1.0f, 0.0f, // triangle 1
     0.25f,  0.5f, -0.25f,  1.0f, 1.0f,
     0.25f, -0.5f, -0.25f,  0.0f, 1.0f,
     0.25f, -0.5f, -0.25f,  0.0f, 1.0f, // triangle 2
     0.25f, -0.5f,  0.25f,  0.0f, 0.0f,
     0.25f,  0.5f,  0.25f,  1.0f, 0.0f,
    // face 5
    -0.25f, -0.5f, -0.25f,  0.0f, 1.0f, // triangle 1
     0.25f, -0.5f, -0.25f,  1.0f, 1.0f,
     0.25f, -0.5f,  0.25f,  1.0f, 0.0f,
     0.25f, -0.5f,  0.25f,  1.0f, 0.0f, // triangle 2
    -0.25f, -0.5f,  0.25f,  0.0f, 0.0f,
    -0.25f, -0.5f, -0.25f,  0.0f, 1.0f,
    // face 6
    -0.25f,  0.5f, -0.25f,  0.0f, 1.0f, // triangle 1
     0.25f,  0.5f, -0.25f,  1.0f, 1.0f,
     0.25f,  0.5f,  0.25f,  1.0f, 0.0f,
     0.25f,  0.5f,  0.25f,  1.0f, 0.0f, // triangle 2
    -0.25f,  0.5f,  0.25f,  0.0f, 0.0f,
    -0.25f,  0.5f, -0.25f,  0.0f, 1.0f
};
static const int kPlayerNumVertices = 36;
static Models::ModelGroup kPlayersModelGroup(kPlayerVertices, sizeof(kPlayerVertices), kPlayerNumVertices);

// cubes

static const float kCubeVertices[] = {
    // face 1
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, // triangle 1
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // triangle 2
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
    // face 2
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // triangle 1
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f, // triangle 2
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    // face 3
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // triangle 1
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // triangle 2
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    // face 4
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // triangle 1
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // triangle 2
     0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    // face 5
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // triangle 1
     0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f, // triangle 2
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    // face 6
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, // triangle 1
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // triangle 2
    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
};
static const int kCubeNumVertices = 36;
static Models::ModelGroup kCubesModelGroup(kCubeVertices, sizeof(kCubeVertices), kCubeNumVertices);

// clang-format on

/**
 * ModelGroup constructor.
 */
Models::ModelGroup::ModelGroup(const float * vertices, const int vertices_size, const int num_vertices)
        : vertices_(vertices), vertices_size_(vertices_size), num_vertices_(num_vertices) {}

/**
 * ModelGroup destructor.
 */
Models::ModelGroup::~ModelGroup() {

    delete positions_;
}

/**
 * Models constructor.
 */
Models::Models(Player * player_ptr, std::vector<EnemyCube> * enemy_cubes_ptr)
        : player_ptr_(player_ptr),
          enemy_cubes_ptr_(enemy_cubes_ptr),
          model_groups_({kFloorsModelGroup, kPlayersModelGroup, kCubesModelGroup}) {

    // set the number of models and the positions of each model group!!!

    // floor
    model_groups_[kFloor].num_models_ = 1;
    model_groups_[kFloor].positions_ = new glm::vec3;
    model_groups_[kFloor].positions_[0] = glm::vec3(0.0f, 0.0f, 0.0f);

    // player
    model_groups_[kPlayer].num_models_ = 1;
    model_groups_[kPlayer].positions_ = new glm::vec3;
    model_groups_[kPlayer].positions_[0] = player_ptr_->GetPosition();

    // enemy cubes
    model_groups_[kCube].num_models_ = enemy_cubes_ptr_->size();
    model_groups_[kCube].positions_ = new glm::vec3[enemy_cubes_ptr_->size()];
    for (int i = 0; i < enemy_cubes_ptr_->size(); i++)
        model_groups_[kCube].positions_[i] = (*enemy_cubes_ptr_)[i].GetPosition();
}

void Models::Update(const float delta_time) {

    // updated player
    model_groups_[kPlayer].positions_[0] = player_ptr_->GetPosition();
}

const float * Models::GetVertices(const int model_group_i) {

    return model_groups_[model_group_i].vertices_;
}

const int Models::GetVerticesSize(const int model_group_i) {

    return model_groups_[model_group_i].vertices_size_;
}

const int Models::GetNumVertices(const int model_group_i) {

    return model_groups_[model_group_i].num_vertices_;
}

const int Models::GetNumModels(const int model_group_i) {

    return model_groups_[model_group_i].num_models_;
}

glm::vec3 * Models::GetPositions(const int model_group_i) {

    return model_groups_[model_group_i].positions_;
}
