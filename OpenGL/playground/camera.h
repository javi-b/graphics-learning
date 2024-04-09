#pragma once

#include "stdafx.h"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "player.h"

/**
 * Camera class.
 */
class Camera {
public:
	// constructors
	explicit Camera(Player * player_ptr);

	// public functions

	void ProcessMouseMovement(const float x_offset, const float y_offset);
	void Update();

	glm::mat4 GetViewMatrix();

	// getters and setters
	float GetHorizontalAngle() { return horizontal_angle_; }

private:
	// private constants
	static const float kDefDistance_;
	static const float kDefSensitivity_;

	// private variables

	Player* player_ptr_;

	float distance_ = kDefDistance_; // distance from the player
	float horizontal_angle_ = 0.0f; // horizontal angle around the player
	float vertical_angle_ = 0.0f; // vertical angle around the player
	float mouse_sensitivity_ = kDefSensitivity_;
	glm::vec3 position_ = glm::vec3(0.0f, 0.0f, 0.0f); // position of the camera
	glm::vec3 target_ = glm::vec3(0.0f, 0.0f, 0.0f); // target position the camera is looking at
	glm::vec3 up_ = glm::vec3(0.0f, 0.0f, 0.0f); // up vector of the camera
};
