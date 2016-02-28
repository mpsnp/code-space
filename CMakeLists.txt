cmake_minimum_required(VERSION 3.0)
project(CodeSpace)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(OpenGL REQUIRED)
find_package(TCLAP REQUIRED)
find_package(Irrlicht REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${OPENGL_INCLUDE_DIR} ${TCLAP_INCLUDE_DIR} ${IRRLICHT_INCLUDE_DIRS})

set(SOURCE_FILES main.cpp)
add_executable(cspace ${SOURCE_FILES})

target_link_libraries(cspace ${OPENGL_LIBRARIES} ${IRRLICHT_LIBRARIES})
