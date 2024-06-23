#include <iostream>
#include <exception>
#include "ClientCommand.h"
#include "System.h"

ClientCommand::ClientCommand()
{
    if (!isCurrentUserClient()) {
        invalidCmd();
    }
}

bool ClientCommand::isCurrentUserClient() const
{
    return System::getInstance().getCurrentUser()->isClient();
}
