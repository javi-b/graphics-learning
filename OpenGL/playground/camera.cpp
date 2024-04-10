#include "camera.h"

const float Camera::kDefDistance_ = 2.0f;
const float Camera::kDefSensitivity_ = 0.2f;

/**
 * Camera default constructor.
 */
Camera::Camera(Player* player_ptr) : player_ptr_(player_ptr) {

    Update();
}

/**
 * Processes input received from a mouse-like system. Expects x and y offset value.
 */
void Camera::ProcessMouseMovement(const float x_offset, const float y_offset) {

    horizontal_angle_ += x_offset * mouse_sensitivity_;
    vertical_angle_ += y_offset * mouse_sensitivity_;

    // Clamp vertical angle to avoid flipping
    if (vertical_angle_ > 89.0f)
        vertical_angle_ = 89.0f;
    else if (vertical_angle_ < -89.0f)
        vertical_angle_ = -89.0f;

    Update();
}

/**
 * Updates camera variables.
 */
void Camera::Update() {

    const auto player_pos = player_ptr_->GetPosition();

    // calculates positions relative to player
    position_.x = player_pos.x - distance_ * cos(glm::radians(horizontal_angle_));
    position_.y = player_pos.y - distance_ * sin(glm::radians(vertical_angle_));
    position_.z = player_pos.z - distance_ * sin(glm::radians(horizontal_angle_));

    // calculates target position
    target_ = player_pos;

    // updates up vector
    const glm::vec3 front = glm::normalize(target_ - position_);
    static const glm::vec3 kWorldUp = glm::vec3(0.0f, 1.0f, 0.0f); // world up is always y axis
    const glm::vec3 right = glm::normalize(glm::cross(front, kWorldUp));
    up_ = glm::normalize(glm::cross(right, front));
}

/**
 * Gets the view matrix calculated using Euler Angles and the LookAt matrix.
 */
glm::mat4 Camera::GetViewMatrix() {
    return glm::lookAt(position_, target_, up_);
}
