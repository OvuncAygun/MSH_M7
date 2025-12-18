#include "MSH_M7.h"
#include "GetModeCommand.h"
#include "ChangeModeCommand.h"
#include "GetStateCommand.h"
#include "ChangeStateCommand.h"
#include "PreviousStateCommand.h"
#include "NextStateCommand.h"
#include "GetDeviceByTypeCommand.h"
#include "GetDeviceByIndexCommand.h"
#include "RemoveDeviceCommand.h"
#include "PoweronDeviceCommand.h"
#include "PoweroffDeviceCommand.h"
#include "AddDeviceCommand.h"
#include "ArmSecurityCommand.h"

MSH_M7::MSH_M7() = default;
MSH_M7::~MSH_M7() = default;

void MSH_M7::setDeviceManager(IDeviceManager* dm) {
    deviceManager = dm;
}

void MSH_M7::setModeManager(IModeManager* mm) {
    modeManager = mm;
}

void MSH_M7::setStateManager(IStateManager* sm) {
    stateManager = sm;
}

void MSH_M7::setLogger(ILogger* l) {
    logger = l;
}

void MSH_M7::setSecurityManager(ISecurityManager* secM) {
    securityManager = secM;
}

void MSH_M7::initializeCommands() {
    commands[0] = new GetModeCommand(deviceManager, modeManager, stateManager, logger, securityManager);
    commands[1] = new ChangeModeCommand(deviceManager, modeManager, stateManager, logger, securityManager);
    commands[2] = new GetStateCommand(deviceManager, modeManager, stateManager, logger, securityManager);
    commands[3] = new ChangeStateCommand(deviceManager, modeManager, stateManager, logger, securityManager);
    commands[4] = new PreviousStateCommand(deviceManager, modeManager, stateManager, logger, securityManager);
    commands[5] = new NextStateCommand(deviceManager, modeManager, stateManager, logger, securityManager);
    commands[6] = new GetDeviceByTypeCommand(deviceManager, modeManager, stateManager, logger, securityManager);
    commands[7] = new GetDeviceByIndexCommand(deviceManager, modeManager, stateManager, logger, securityManager);
    commands[8] = new RemoveDeviceCommand(deviceManager, modeManager, stateManager, logger, securityManager);
    commands[9] = new PoweronDeviceCommand(deviceManager, modeManager, stateManager, logger, securityManager);
    commands[10] = new PoweroffDeviceCommand(deviceManager, modeManager, stateManager, logger, securityManager);
    commands[11] = new AddDeviceCommand(deviceManager, modeManager, stateManager, logger, securityManager);
    commands[12] = new ArmSecurityCommand(deviceManager, modeManager, stateManager, logger, securityManager);
}

std::vector<ICommand*> MSH_M7::getCommands() {
    return commands;
}