#ifndef MSH_M7_H
#define MSH_M7_H

#include "ICommand.h"
#include "IDeviceManager.h" 
#include "IModeManager.h"
#include "IStateManager.h"
#include "ILogger.h"
#include "ISecurityManager.h"
#include "IDevice.h"
#include <map>
#include <string>
#include <vector>
#include <cstdio>

class MSH_M7 {
public:
    MSH_M7();
    ~MSH_M7();

    void setDeviceManager(IDeviceManager* dm);
    void setModeManager(IModeManager* mm);
    void setStateManager(IStateManager* sm);
    void setLogger(ILogger* l);
    void setSecurityManager(ISecurityManager* secM);

    void initializeCommands();

    std::vector<ICommand*> getCommands();

private:
    IDeviceManager* deviceManager;
    IModeManager* modeManager;
    IStateManager* stateManager;
    ILogger* logger;
    ISecurityManager* securityManager;

    std::vector<ICommand*> commands;
};

#endif