//
// Created by George Kiriy on 26/02/16.
//

#ifndef CODESPACE_CSERVICECOORDINATOR_H
#define CODESPACE_CSERVICECOORDINATOR_H

//class IServiceCoordinator;

#include "../IServiceCoordinator.h"

class CServiceCoordinator : public IServiceCoordinator {
public:
    virtual IRenderer *renderer();
};


#endif //CODESPACE_CSERVICECOORDINATOR_H
