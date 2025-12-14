#pragma once

#include <string>

class IModeStrategy {
public:
    virtual ~IModeStrategy() = default;

    virtual std::string getModeName() const = 0;
};