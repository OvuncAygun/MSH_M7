#pragma once

#include "IModeStrategy.h"

class IModeManager {
public:
    virtual ~IModeManager() = default;

    virtual void setMode(IModeStrategy* mode) = 0;
    virtual std::string getModeName() const = 0;
};