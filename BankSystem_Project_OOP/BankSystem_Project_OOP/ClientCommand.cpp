#include <iostream>
#include <exception>
#include "ClientCommand.h"
#include "System.h"

ClientCommand::ClientCommand(System* sPtr) : UserCommand(sPtr)
{
    if (!isCurrentUserClient()) {
        invalidCmd();
    }
}

bool ClientCommand::isCurrentUserClient() const
{
    return sPtr->currentUser->isClient();
}
