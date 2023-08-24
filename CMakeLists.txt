cmake_minimum_required(VERSION 3.0.0)
project(LearnOpenGl)

add_executable(LearnOpenGl src/main.cpp)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glad)
target_link_libraries(LearnOpenGl glad)

add_subdirectory(external/glfw)
target_link_libraries(LearnOpenGl glfw)

add_subdirectory(external/glm)
target_link_libraries(LearnOpenGl glm)
