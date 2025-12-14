cmake_minimum_required(VERSION 3.10)
project(MSH_M7 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(MSH_M7)

target_include_directories(MSH_M7
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include/commands
    
    PRIVATE
        src
        external
)

target_sources(MSH_M7
    PRIVATE
        src/MSH_M7.cpp
    
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/MSH_M7.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/ICommand.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/commands/GetModeCommand.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/commands/ChangeModeCommand.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/commands/GetStateCommand.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/commands/ChangeStateCommand.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/commands/PreviousStateCommand.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/commands/NextStateCommand.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/commands/GetDeviceByTypeCommand.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/commands/GetDeviceByIndexCommand.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/commands/RemoveDeviceCommand.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/commands/PowerOnDeviceCommand.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/commands/PoweroffDeviceCommand.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/commands/AddDeviceCommand.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/commands/ArmSecurityCommand.h
)

include(CTest)
enable_testing()

