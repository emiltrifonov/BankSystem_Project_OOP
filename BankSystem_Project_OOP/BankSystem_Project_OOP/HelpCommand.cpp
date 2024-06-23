#include <iostream>
#include <exception>
#include "HelpCommand.h"
#include "System.h"

HelpCommand::HelpCommand()
{
	if (!System::getInstance().isUserLogged()) {
		invalidCmd();
	}
}

void HelpCommand::execute()
{
	System::getInstance().getCurrentUser()->help();
}
