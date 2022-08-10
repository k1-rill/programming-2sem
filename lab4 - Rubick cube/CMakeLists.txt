cmake_minimum_required(VERSION 3.21)
project(lab4)

set(CMAKE_CXX_STANDARD 17)
include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/library)

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

set(CMAKE_OSX_ARCHITECTURES "arm64")
add_executable(lab4 main.cpp cube.cpp cube.h visual.h visual.cpp)
target_link_libraries(lab4 glfw)
target_link_libraries(lab4 OpenGL::GL)
target_link_libraries(lab4 "-framework GLUT")
