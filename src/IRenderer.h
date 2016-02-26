//
// Created by George Kiriy on 26/02/16.
//

#ifndef CODESPACE_IRENDERER_H
#define CODESPACE_IRENDERER_H

#include <GLFW/glfw3.h>

class IRenderer {
public:
    virtual void render(GLFWwindow *window) = 0;
};

#endif //CODESPACE_IRENDERER_H
