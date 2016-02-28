#include <irrlicht.h>
#include <tclap/CmdLine.h>


using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

int main(int argc, char **argv) {
    TCLAP::CmdLine cmd("Space Code --- source code visualisation tool", ' ', "0.1");
    TCLAP::SwitchArg fullScreenArg("f", "fullscreen", "Open in full screen window", cmd);
    TCLAP::SwitchArg vsyncArg("v", "vsync", "Enable vertical synchronisation", cmd);
    TCLAP::ValueArg<u32> widthArg("W", "width", "Width of viewport", false, 640, "int", cmd);
    TCLAP::ValueArg<u32> heightArg("H", "height", "Height of viewport", false, 480, "int", cmd);
    cmd.parse(argc, (const char *const *) argv);

    const dimension2d<u32> &windowSize = core::dimension2d<u32>(widthArg.getValue(), heightArg.getValue());
    u32 bits = 16;
    bool fullscreen = fullScreenArg.getValue();
    bool stencilbuffer = false;
    bool vsync = vsyncArg.getValue();
    IrrlichtDevice *device = createDevice(EDT_OPENGL, windowSize, bits, fullscreen, stencilbuffer, vsync);
    if (device == 0) return 1;

    IVideoDriver *driver = device->getVideoDriver();
    ISceneManager *smgr = device->getSceneManager();

    while (device->run())
        if (device->isWindowActive()) {

            driver->beginScene(true, true, SColor(0, 0, 0, 0));
            smgr->drawAll();
            driver->endScene();
        }

    device->drop();

    return 0;
}