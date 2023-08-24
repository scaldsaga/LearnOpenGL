#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <sstream>
#include <fstream>

class ShaderProgram
{
private:
    GLuint progID = 0;
    bool isOk = true;

    bool createShader(GLuint &shaderID, std::string &source, GLenum shaderType);
    bool errorsInfo(GLuint ID);

public:
    ShaderProgram(std::string &vertexShaderPath, std::string &fragmentShaderPath);

    GLuint ID() { return progID; }
    void use() { glUseProgram(progID); }
};
