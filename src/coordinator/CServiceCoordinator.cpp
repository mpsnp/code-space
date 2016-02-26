//
// Created by George Kiriy on 26/02/16.
//

#include "CServiceCoordinator.h"
#include "../render/CRenderer.h"

IRenderer *CServiceCoordinator::renderer() {
    static IRenderer *render;
    if (!render)
        render = new CRenderer();
    return render;
}
