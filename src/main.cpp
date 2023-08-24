#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

int window_width = 900;
int window_height = 600;

int main()
{
    if (!glfwInit())
    {
        std::cerr << "ERROR::GLFW_INIT_ERROR\n";
        glfwTerminate();
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
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

    while (!glfwWindowShouldClose(pWindow))
    {
        glClearColor(0.2, 0.2, 0.2, 0.0);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glfwSwapBuffers(pWindow);
        glfwPollEvents();
    }

    glfwTerminate();
}