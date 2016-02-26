//
// Created by George Kiriy on 26/02/16.
//

#include "IServiceCoordinator.h"
#include "coordinator/CServiceCoordinator.h"

IServiceCoordinator *IServiceCoordinator::sharedInstance() {
    static IServiceCoordinator *coordinator;
    if (!coordinator)
        coordinator = new CServiceCoordinator();
    return coordinator;
}
