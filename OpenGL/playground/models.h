#pragma once

#include <iostream>
#include <cstdlib>
#include <array>
#include <glm/glm.hpp>

/**
 * Models class.
 */
class Models {
public:

	enum ModelGroupName {
		kFloor,
		kCube,
		kNumModelGroups
	};

	// constructor
	Models();

	// public functions

	void Update(const float delta_time);

	const float* GetVertices(const int model_group_i);
	const int GetVerticesSize(const int model_group_i);
	const int GetNumVertices(const int model_group_i);
	const int GetNumModels(const int model_group_i);

	glm::vec3* GetPositions(const int model_group_i);

private:

	/**
	 * ModelGroup data structure.
	 */
	struct ModelGroup {
		const float * vertices_;
		const int vertices_size_;
		const int num_vertices_;
		const int num_models_;
		glm::vec3 * positions_;

		ModelGroup(const float * vertices, const int vertices_size,
			const int num_vertices, const int num_models, const glm::vec3 * initial_positions);
	};

	// private variables
	std::array<ModelGroup, kNumModelGroups> model_groups_;
};
