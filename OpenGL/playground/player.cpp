#include "player.h"

/**
 * Processes the keyboard input and apply necessary changes to the player.
 */
void Player::ProcessKeyboard(const Direction direction, const float delta_time) {

	const float velocity = movement_speed_ * delta_time;
	const float angle = glm::radians(horizontal_angle_);
	const float x_movement = velocity * cos(angle);
	const float z_movement = velocity * sin(angle);

	switch (direction) {
	case kForward:
		position_.x += x_movement;
		position_.z += z_movement;
		break;
	case kBackward:
		position_.x -= x_movement;
		position_.z -= z_movement;
		break;
	case kLeft:
		position_.x += z_movement;
		position_.z -= x_movement;
		break;
	case kRight:
		position_.x -= z_movement;
		position_.z += x_movement;
		break;
	}
}