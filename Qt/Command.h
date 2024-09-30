#pragma once

#include <QString>

class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
};

