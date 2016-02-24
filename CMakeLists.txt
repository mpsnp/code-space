cmake_minimum_required(VERSION 3.0)
project(CodeSpace)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(GLFW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(Boost REQUIRED COMPONENTS program_options)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${GLFW_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${Boost_INCLUDE_DIRS})

set(SOURCE_FILES main.cpp)
add_executable(cspace ${SOURCE_FILES})

target_link_libraries(cspace ${GLFW_LIBRARIES} ${OPENGL_LIBRARIES} ${Boost_LIBRARIES})
