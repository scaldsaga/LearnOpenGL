#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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

    void unifomMat4fv(glm::mat4 &mat4, const char *matName)
    {
        glUniformMatrix4fv(glGetUniformLocation(progID, matName), 1, GL_FALSE, glm::value_ptr(mat4));
    }

    GLuint ID() { return progID; }
    void use() { glUseProgram(progID); }
};
