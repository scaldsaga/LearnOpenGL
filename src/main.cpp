#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "render/ShaderProgram.h"

int window_width = 900;
int window_height = 600;

int main()
{
    if (!glfwInit())
    {
        std::cerr << "ERROR::GLFW_INIT_ERROR\n";
        glfwTerminate();
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *pWindow = glfwCreateWindow(window_width, window_height, "OpenGl", nullptr, nullptr);
    if (!pWindow)
    {
        std::cerr << "ERROR::WINDOW_CREATION_ERROR\n";
        glfwTerminate();
    }

    glfwMakeContextCurrent(pWindow);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "ERROR::GLAD_INIT_ERROR\n";
        glfwTerminate();
    }

    std::string vertexPath("D:/projects/LearnOpenGL/shaders/vertexSahder.txt");
    std::string fragmentPath("D:/projects/LearnOpenGL/shaders/fragmentShader.txt");

    ShaderProgram program(vertexPath, fragmentPath);

    while (!glfwWindowShouldClose(pWindow))
    {
        glClearColor(0.2, 0.2, 0.2, 0.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(pWindow);
        glfwPollEvents();
    }

    glfwTerminate();
}