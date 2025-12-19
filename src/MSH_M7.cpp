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
    commands.push_back(
        new GetModeCommand(deviceManager, modeManager, stateManager, logger, securityManager));
    commands.push_back(
        new ChangeModeCommand(deviceManager, modeManager, stateManager, logger, securityManager));
    commands.push_back(
        new GetStateCommand(deviceManager, modeManager, stateManager, logger, securityManager));
    commands.push_back(
        new ChangeStateCommand(deviceManager, modeManager, stateManager, logger, securityManager));
    commands.push_back(
        new PreviousStateCommand(deviceManager, modeManager, stateManager, logger, securityManager));
    commands.push_back(
        new NextStateCommand(deviceManager, modeManager, stateManager, logger, securityManager));
    commands.push_back(
        new GetDeviceByTypeCommand(deviceManager, modeManager, stateManager, logger, securityManager));
    commands.push_back(
        new GetDeviceByIndexCommand(deviceManager, modeManager, stateManager, logger, securityManager));
    commands.push_back(
        new RemoveDeviceCommand(deviceManager, modeManager, stateManager, logger, securityManager));
    commands.push_back(
        new PoweronDeviceCommand(deviceManager, modeManager, stateManager, logger, securityManager));
    commands.push_back(
        new PoweroffDeviceCommand(deviceManager, modeManager, stateManager, logger, securityManager));
    commands.push_back(
        new AddDeviceCommand(deviceManager, modeManager, stateManager, logger, securityManager));
    commands.push_back(
        new ArmSecurityCommand(deviceManager, modeManager, stateManager, logger, securityManager));
}

std::vector<ICommand*> MSH_M7::getCommands() {
    return commands;
}