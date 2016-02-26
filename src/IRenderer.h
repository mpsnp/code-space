//
// Created by George Kiriy on 26/02/16.
//

#ifndef CODESPACE_IRENDERER_H
#define CODESPACE_IRENDERER_H

#include <GLFW/glfw3.h>
#include "IRenderable.h"
#include "ICamera.h"

class IRenderer {
public:
    virtual void render(GLFWwindow *window) = 0;

    virtual void addObject(IRenderable *object) = 0;
    virtual IRenderable *removeObject(IRenderable *object) = 0;

    virtual ICamera *camera() = 0;
    virtual void setCamera(ICamera *iCamera) = 0;
};

#endif //CODESPACE_IRENDERER_H
