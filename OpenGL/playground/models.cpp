#include "models.h"

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
static const int kNumFloors = 1;
static const glm::vec3 kFloorInitialPositions[kNumFloors] = {
	glm::vec3(0.0f, 0.0f, 0.0f)
};

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
static const int kNumCubes = 10;
static const glm::vec3 kCubesIntitialPositions[kNumCubes] = {
	glm::vec3(0.0f, 0.0f, 0.0f),
	glm::vec3(2.0f, 5.0f, -15.0f),
	glm::vec3(-1.5f, -2.2f, -2.5f),
	glm::vec3(-3.8f, -2.0f, -12.3f),
	glm::vec3(2.4f, -0.4f, -3.5f),
	glm::vec3(-1.7f, 3.0f, -7.5f),
	glm::vec3(1.3f, -2.0f, -2.5f),
	glm::vec3(1.5f, 2.0f, -2.5f),
	glm::vec3(1.5f, 0.2f, -1.5f),
	glm::vec3(-1.3f, 1.0f, -1.5f)
};

Models::Models()
	: model_groups_({
		ModelGroup(kFloorVertices, sizeof(kFloorVertices), kFloorNumVertices, kNumFloors, kFloorInitialPositions),
		ModelGroup(kCubeVertices, sizeof(kCubeVertices), kCubeNumVertices, kNumCubes, kCubesIntitialPositions)
	}) {}

void Models::Update(const float delta_time) {

	auto* positions = model_groups_[kCube].positions_;
	for (int i = 0; i < model_groups_[kCube].num_models_; i++) {
		positions[i][0] += ((float(std::rand()) / RAND_MAX) * 2.0f - 1.0f) * 2.0f * delta_time;
		positions[i][1] += 0.3f * delta_time;
		positions[i][2] += ((float(std::rand()) / RAND_MAX) * 2.0f - 1.0f) * 2.0f * delta_time;
	}
}

const float* Models::GetVertices(const int model_group_i) {

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

glm::vec3* Models::GetPositions(const int model_group_i) {

	return model_groups_[model_group_i].positions_;
}

Models::ModelGroup::ModelGroup(const float* vertices, const int vertices_size,
		const int num_vertices, const int num_models, const glm::vec3* initial_positions)
	: vertices_(vertices), vertices_size_(vertices_size),
		num_vertices_(num_vertices), num_models_(num_models) {

	positions_ = const_cast<glm::vec3*>(initial_positions);
}
