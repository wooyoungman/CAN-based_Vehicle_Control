#pragma once

#include "Command.h"
#include "DatabaseManager.h"

class DriveCommand : public Command {
private:
    DatabaseManager* dbManager;
    QString command;

public:
    DriveCommand(DatabaseManager* dbManager, const QString& command)
        : dbManager(dbManager), command(command) {}

    void execute() override {
        dbManager->insertCommand(command, "0");
    }
};

