
#ifndef COMMAND_H
#define COMMAND_H

#include "ICommand.h"
#include "IDeviceManager.h"
#include "IModeManager.h"
#include "IStateManager.h"
#include "ILogger.h"
#include "ISecurityManager.h"
#include "DeviceType.h"       
#include "Utility.h" 

class Command : public ICommand {
protected:
    IDeviceManager* deviceManager;
    IModeManager* modeManager;
    IStateManager* stateManager;
    ILogger* logger;
    ISecurityManager* securityManager;

public:

    Command(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM)
        : deviceManager(dm), modeManager(mm), stateManager(sm), logger(l), securityManager(secM) {
    }

    virtual ~Command() {}
};

#endif 