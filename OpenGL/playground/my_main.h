#pragma once

#include "stdafx.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shader.h"
#include "camera.h"
#include "models.h"
#include "player.h"

/**
 * MyMain class.
 */
class MyMain {
public:
	// constructor
	MyMain();

	// public funtions
	int Run();
	void MouseCallback(GLFWwindow* window, double xpos, double ypos);

private:
	// private constants
	static const unsigned int kScrW_ = 800;
	static const unsigned int kScrH_ = 600;

	// private variables

	static MyMain* current_instance_;

	Player player_ = Player();
	Camera camera_ = Camera(&player_);
	float mouse_last_x_ = kScrW_ / 2.0f;
	float mouse_last_y_ = kScrH_ / 2.0f;
	bool is_first_mouse_frame_ = true;

	float delta_time_ = 0.0f; // time between current frame and last frame
	float last_frame_ = 0.0f;

	// private functions
	static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
	static void StaticMouseCallback(GLFWwindow* window, double xpos, double ypos);
	void ProcessInput(GLFWwindow* window);
};
