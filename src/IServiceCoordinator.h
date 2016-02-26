//
// Created by George Kiriy on 26/02/16.
//

#ifndef CODESPACE_ISERVICECOORDINATOR_H
#define CODESPACE_ISERVICECOORDINATOR_H

class CServiceCoordinator;

class IRenderer;

class IServiceCoordinator {
public:
    static IServiceCoordinator *sharedInstance();

    virtual IRenderer *renderer() = 0;

};

#endif //CODESPACE_ISERVICECOORDINATOR_H
