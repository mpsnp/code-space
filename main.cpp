#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

int main(int argc, char **argv) {
    const dimension2d<u32> &windowSize = core::dimension2d<u32>(640, 480);
    int bits = 16;
    bool fullscreen = false;
    bool stencilbuffer = false;
    bool vsync = false;
    IrrlichtDevice *device = createDevice(EDT_OPENGL, windowSize, bits, fullscreen, stencilbuffer, vsync);
    if (device == 0) return 1;

    IVideoDriver *driver = device->getVideoDriver();
    ISceneManager *smgr = device->getSceneManager();

    while (device->run())
        if (device->isWindowActive()) {

            driver->beginScene(true, true, SColor(0, 3, 243, 250));
            smgr->drawAll();
            driver->endScene();
        }

    device->drop();

    return 0;
}