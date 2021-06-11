#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <main.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    // When the window is resized, set the new viewport size to be the same as the new window size
    glViewport(0, 0, width, height);
}

int main() {
    // Initialise GLFW and setup some basic config
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create the window object
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Test", nullptr, nullptr);

    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Initialise GLAD
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Setup the viewport
    glViewport(0, 0, 800, 600);

    // Resize the viewport as the window is resized
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Chill until we need to quit
    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
