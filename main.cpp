#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <tclap/CmdLine.h>

static void errorCallback(int error, const char *description) {
    fputs(description, stderr);
}

static void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

void mainLoop(GLFWwindow *window) {
    while (!glfwWindowShouldClose(window)) {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.6f, -0.4f, 0.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.6f, 0.f);
        glEnd();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

int main(int argc, char **argv) {

    TCLAP::CmdLine cmd("Space Code --- source code visualisation tool", ' ', "0.1");
    TCLAP::SwitchArg fullScreenArg("f", "fullscreen", "Open in full screen window", cmd);
    TCLAP::SwitchArg autosizeArg("a", "autosize", "Use current resolution", cmd);
    TCLAP::ValueArg<int> widthArg("W", "width", "Width of viewport", false, 640, "int", cmd);
    TCLAP::ValueArg<int> heightArg("H", "height", "Height of viewport", false, 480, "int", cmd);
    cmd.parse(argc, (const char *const *) argv);

    // Init GLFW
    GLFWwindow *window;
    glfwSetErrorCallback(errorCallback);
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }

    // Create window
    GLFWmonitor *monitor = glfwGetPrimaryMonitor();
    bool fullScreen = fullScreenArg.getValue();
    int width = widthArg.getValue();
    int height = heightArg.getValue();
    if (autosizeArg.getValue()) {
        const GLFWvidmode *mode = glfwGetVideoMode(monitor);
        width = mode->width;
        height = mode->height;
    }
    window = glfwCreateWindow(width, height, "Simple example", fullScreen ? monitor : NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // Start drawing loop
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, keyCallback);
    mainLoop(window);
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}