cmake_minimum_required(VERSION 3.19)
project(SDLTest VERSION 1.0
                DESCRIPTION "Very interesting project")

set(CMAKE_CXX_STANDARD 14)

set(GLAD_DIR Libraries/include/glad)
set(GLFW_DIR Libraries/include/GLFW)
set(KHR_DIR Libraries/include/KHR)
set(LIB_DIR Libraries/lib)

set(SOURCES main.cpp glad.c ${GLAD_DIR}/glad.h ${GLFW_DIR}/glfw3.h ${KHR_DIR}/khrplatform.h include/main.h)

add_executable(output ${SOURCES})

target_link_libraries(output ${PROJECT_SOURCE_DIR}/${LIB_DIR}/glfw3.lib)
target_include_directories(output PRIVATE Libraries/include)
target_include_directories(output PRIVATE include)
