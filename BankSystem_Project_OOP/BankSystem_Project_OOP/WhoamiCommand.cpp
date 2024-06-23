#include <iostream>
#include <exception>
#include "WhoamiCommand.h"
#include "System.h"

WhoamiCommand::WhoamiCommand(System* s) : UserCommand(s) { }

void WhoamiCommand::execute()
{
	sPtr->currentUser->whoami();
}
