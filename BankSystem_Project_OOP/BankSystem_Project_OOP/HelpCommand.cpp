#include <iostream>
#include <exception>
#include "HelpCommand.h"
#include "System.h"

HelpCommand::HelpCommand(System* sPtr)
{
	this->sPtr = sPtr;

	if (!sPtr->currentUser) {
		invalidCmd();
	}
}

void HelpCommand::execute()
{
	sPtr->currentUser->help();
}
