//
// Created by George Kiriy on 26/02/16.
//

#ifndef CODESPACE_CRENDERER_H
#define CODESPACE_CRENDERER_H

#include "../IRenderer.h"

class CRenderer : public IRenderer {
public:
    virtual void render(GLFWwindow *window);
};


#endif //CODESPACE_CRENDERER_H
