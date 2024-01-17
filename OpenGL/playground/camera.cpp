#include "camera.h"

const float Camera::kDefYaw_ = -90.0f;
const float Camera::kDefPitch_ = 0.0f;
const float Camera::kDefSpeed_ = 2.5f;
const float Camera::kDefSensitivity_ = 0.2f;

/**
 * Camera constructor from vectors.
 */
Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
	: position_(position), front_(glm::vec3(0.0f, 0.0f, -1.0f)), world_up_(up),
	yaw_(yaw), pitch_(pitch), movement_speed_(kDefSpeed_),
	mouse_sensitivity_(kDefSensitivity_) {

	UpdateCameraVectors();
}

/**
 * Camera constructor from scalar values.
 */
Camera::Camera(const float pos_x, const float pos_y, const float pos_z,
	const float up_x, const float up_y, const float up_z,
	const float yaw, const float pitch)
	: position_(glm::vec3(pos_x, pos_y, pos_z)), front_(glm::vec3(0.0f, 0.0f, -1.0f)),
	world_up_(glm::vec3(up_x, up_y, up_z)), yaw_(yaw), pitch_(pitch),
	movement_speed_(kDefSpeed_), mouse_sensitivity_(kDefSensitivity_) {

	UpdateCameraVectors();
}

/**
 * Gets the view matrix calculated using Euler Angles and the LookAt matrix.
 */
glm::mat4 Camera::GetViewMatrix() {
	return glm::lookAt(position_, position_ + front_, up_);
}

/**
 * Processes input received from any keyboard-like system. Accepts input parameter
 * in form of defined Direction ENUM.
 */
void Camera::ProcessKeyboard(const Direction direction, const float delta_time) {

	const float velocity = movement_speed_ * delta_time;

	if (direction == kForward)
		position_ += front_ * velocity;
	if (direction == kBackward)
		position_ -= front_ * velocity;
	if (direction == kLeft)
		position_ -= right_ * velocity;
	if (direction == kRight)
		position_ += right_ * velocity;
}

/**
 * Processes input received from a mouse-like system. Expects x and y offset value.
 */
void Camera::ProcessMouseMovement(const float x_offset, const float y_offset,
	GLboolean constrain_pitch) {

	yaw_ += x_offset * mouse_sensitivity_;
	pitch_ += y_offset * mouse_sensitivity_;

	// make sure that when pitch is out of bounds, screen doesn't flip
	if (constrain_pitch) {
		if (pitch_ > 89.0f)
			pitch_ = 89.0f;
		if (pitch_ < -89.0f)
			pitch_ = -89.0f;
	}

	UpdateCameraVectors();
}

/**
 * Calculates the front vector from the Camera's updated Euler Angles.
 */
void Camera::UpdateCameraVectors() {

	glm::vec3 front;
	front.x = cos(glm::radians(yaw_)) * cos(glm::radians(pitch_));
	front.y = sin(glm::radians(pitch_));
	front.z = sin(glm::radians(yaw_)) * cos(glm::radians(pitch_));
	front_ = glm::normalize(front);

	right_ = glm::normalize(glm::cross(front_, world_up_));
	up_ = glm::normalize(glm::cross(right_, front_));
}
