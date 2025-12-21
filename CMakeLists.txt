cmake_minimum_required(VERSION 3.10)
project(MSH_M7 LANGUAGES CXX)

add_library(MSH_M7)

target_link_libraries(MSH_M7 PUBLIC MSH_M1 MSH_M2 MSH_M3 MSH_M4 MSH_M5 MSH_M6)

target_include_directories(MSH_M7
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include/commands
    
    PRIVATE
        src
)

target_sources(MSH_M7
    PRIVATE
        src/MSH_M7.cpp
        src/Command.h
        src/GetModeCommand.h
        src/ChangeModeCommand.h
        src/GetStateCommand.h
        src/ChangeStateCommand.h
        src/PreviousStateCommand.h
        src/NextStateCommand.h
        src/GetDeviceByTypeCommand.h
        src/GetDeviceByIndexCommand.h
        src/RemoveDeviceCommand.h
        src/PoweronDeviceCommand.h
        src/PoweroffDeviceCommand.h
        src/AddDeviceCommand.h
        src/ArmSecurityCommand.h
    
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/MSH_M7.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/ICommand.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/commands/IGetModeCommand.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/commands/IChangeModeCommand.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/commands/IGetStateCommand.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/commands/IChangeStateCommand.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/commands/IPreviousStateCommand.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/commands/INextStateCommand.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/commands/IGetDeviceByTypeCommand.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/commands/IGetDeviceByIndexCommand.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/commands/IRemoveDeviceCommand.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/commands/IPoweronDeviceCommand.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/commands/IPoweroffDeviceCommand.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/commands/IAddDeviceCommand.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/commands/IArmSecurityCommand.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Utility.h
)

include(CTest)
enable_testing()