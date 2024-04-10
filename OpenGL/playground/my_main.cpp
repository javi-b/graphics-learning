#include "my_main.h"

MyMain * MyMain::current_instance_ = nullptr;

/**
 * Main class default contructor.
 */
MyMain::MyMain() {

    current_instance_ = this;
}

/**
 * Main function.
 */
int MyMain::Run() {

    // glfw: initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    GLFWwindow * window = glfwCreateWindow(kScrW_, kScrH_, "playground", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); // hiddeen and virtual unlimited cursor
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, MyMain::FramebufferSizeCallback);
    glfwSetCursorPosCallback(window, MyMain::StaticMouseCallback);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // configure global opengl state
    glEnable(GL_DEPTH_TEST);
    // uncomment this call to draw in wireframe polygons.
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // build and compile our shader zprogram
    Shader shader("camera.vert", "camera.frag");

    // models
    Models models(&player_);

    // Vertex Array Objects
    GLuint vaos[Models::kNumModelGroups]; // Vertex Array Objects
    glGenVertexArrays(Models::kNumModelGroups, vaos);

    // Vertex Buffer Objects
    GLuint vbos[Models::kNumModelGroups];
    glGenBuffers(Models::kNumModelGroups, vbos);

    for (int i = 0; i < Models::kNumModelGroups; i++) {

        glBindVertexArray(vaos[i]);

        glBindBuffer(GL_ARRAY_BUFFER, vbos[i]);
        glBufferData(GL_ARRAY_BUFFER, models.GetVerticesSize(i), models.GetVertices(i), GL_STATIC_DRAW);

        // position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0);
        // texture coord attribute
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
    }

    shader.Use();

    // pass projection matrix to shader (as projection matrix rarely changes there's no need to do this per frame)
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)kScrW_ / (float)kScrH_, 0.1f, 100.0f);
    shader.SetMat4("projection", projection);

    // render loop
    while (!glfwWindowShouldClose(window)) {

        // per-frame time logic
        float current_frame = static_cast<float>(glfwGetTime());
        delta_time_ = current_frame - last_frame_;
        last_frame_ = current_frame;

        // input
        ProcessInput(window);

        // update
        camera_.Update();
        models.Update(delta_time_);

        // render
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // activate shader
        shader.Use();

        // camera/view transformation
        glm::mat4 view = camera_.GetViewMatrix();
        shader.SetMat4("view", view);

        const glm::vec3 fill_color({1.0, 1.0, 1.0});
        const glm::vec3 line_color({1.0, 0.0, 0.0});

        // render models
        for (int model_group_i = 0; model_group_i < Models::kNumModelGroups; model_group_i++) {

            glBindVertexArray(vaos[model_group_i]);
            auto positions = models.GetPositions(model_group_i);
            auto num_vertices = models.GetNumVertices(model_group_i);

            for (int model_i = 0; model_i < models.GetNumModels(model_group_i); model_i++) {

                // calculate the model matrix for each object and pass it to shader before drawing
                glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
                model = glm::translate(model, positions[model_i]);
                //float angle = 20.0f * model_i;
                //model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
                shader.SetMat4("model", model);

                glDrawArrays(GL_TRIANGLES, 0, num_vertices);
            }
        }

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    glDeleteVertexArrays(Models::kNumModelGroups, vaos);
    glDeleteBuffers(Models::kNumModelGroups, vbos);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    glfwTerminate();
    return 0;
}

/**
 * process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
 */
void MyMain::ProcessInput(GLFWwindow * window) {

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        player_.ProcessKeyboard(Player::kForward, delta_time_);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        player_.ProcessKeyboard(Player::kBackward, delta_time_);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        player_.ProcessKeyboard(Player::kLeft, delta_time_);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        player_.ProcessKeyboard(Player::kRight, delta_time_);
}

/**
 * glfw: whenever the window size changed (by OS or user resize) this callback function executes
 */
void MyMain::FramebufferSizeCallback(GLFWwindow * window, int width, int height) {

    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

/**
 * glfw: whenever the mouse moves, this callback is called
 */
void MyMain::StaticMouseCallback(GLFWwindow * window, double xpos_in, double ypos_in) {

    if (current_instance_)
        current_instance_->MouseCallback(window, xpos_in, ypos_in);
}

/**
 * glfw: whenever the mouse moves, this callback is called
 */
void MyMain::MouseCallback(GLFWwindow * window, double xpos_in, double ypos_in) {

    float xpos = static_cast<float>(xpos_in);
    float ypos = static_cast<float>(ypos_in);

    if (is_first_mouse_frame_) {
        mouse_last_x_ = xpos;
        mouse_last_y_ = ypos;
        is_first_mouse_frame_ = false;
    }

    float xoffset = xpos - mouse_last_x_;
    float yoffset = mouse_last_y_ - ypos; // reversed since y-coordinates go from bottom to top

    mouse_last_x_ = xpos;
    mouse_last_y_ = ypos;

    camera_.ProcessMouseMovement(xoffset, yoffset);
    player_.SetHorizontalAngle(camera_.GetHorizontalAngle());
}
