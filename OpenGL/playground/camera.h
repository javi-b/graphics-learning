#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

/**
 * Camera class.
 */
class Camera {
public:

	enum Direction {
		kForward,
		kBackward,
		kLeft,
		kRight
	};

	// constants
	static const float kDefYaw_;
	static const float kDefPitch_;
	static const float kDefSpeed_;
	static const float kDefSensitivity_;

	// variables
	glm::vec3 position_;
	glm::vec3 front_;
	glm::vec3 up_;
	glm::vec3 right_;
	glm::vec3 world_up_;
	float yaw_;
	float pitch_;
	float movement_speed_;
	float mouse_sensitivity_;

	// constructors
	Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
		float yaw = kDefYaw_, float pitch = kDefPitch_);
	Camera(const float pos_x, const float pos_y, const float pos_z,
		const float up_x, const float up_y, const float up_z,
		const float yaw, const float pitch);

	// public functions
	glm::mat4 GetViewMatrix();
	void ProcessKeyboard(const Direction direction, const float delta_time);
	void ProcessMouseMovement(const float x_offset, const float y_offset,
		const GLboolean constrain_pitch = true);

private:
	// private functions
	void UpdateCameraVectors();
};
