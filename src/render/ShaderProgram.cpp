#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(std::string &vertexShaderPath, std::string &fragmentShaderPath)
{
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;

    vShaderFile.open(vertexShaderPath);
    fShaderFile.open(fragmentShaderPath);

    std::stringstream vertexStr, fragmentStr;

    vertexStr << vShaderFile.rdbuf();
    fragmentStr << fShaderFile.rdbuf();

    std::string vertexCode, fragmentCode;

    vertexCode = vertexStr.str();
    fragmentCode = fragmentStr.str();

    GLuint vertexShader;
    if (!createShader(vertexShader, vertexCode, GL_VERTEX_SHADER))
        std::cerr << ": VERTEX_SHADER_CREATION_ERROR -------\n\n";

    GLuint fragmentShader;
    if (!createShader(fragmentShader, fragmentCode, GL_FRAGMENT_SHADER))
        std::cerr << ": FRAGMENT_SHADER_CREATION_ERROR -----\n\n";

    progID = glCreateProgram();
    glAttachShader(progID, vertexShader);
    glAttachShader(progID, fragmentShader);
    glLinkProgram(progID);

    if (!errorsInfo(progID))
        std::cerr << ": PROGRAM_CREATION_ERROR -------------\n\n";

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

bool ShaderProgram::createShader(GLuint shaderID, std::string &source, GLenum shaderType)
{
    shaderID = glCreateShader(shaderType);
    const char *code = source.c_str();
    glShaderSource(shaderID, 1, &code, nullptr);
    glCompileShader(shaderID);

    return errorsInfo(shaderID);
}

bool ShaderProgram::errorsInfo(GLuint ID)
{
    int success = 1;
    char infoLog[1024];
    if (this->progID == ID)
    {
        glGetShaderiv(progID, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(progID, sizeof(infoLog), nullptr, infoLog);
            std::cerr << "ERROR::" << infoLog;
            return isOk = false;
        }
        return isOk;
    }
    else
    {
        glGetShaderiv(ID, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(ID, sizeof(infoLog), nullptr, infoLog);
            std::cerr << "ERROR::" << infoLog;
            return isOk = false;
        }
        return isOk;
    }
}
