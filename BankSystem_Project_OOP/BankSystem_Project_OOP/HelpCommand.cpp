#include <iostream>
#include <exception>
#include "HelpCommand.h"
#include "System.h"

HelpCommand::HelpCommand()
{
	if (!System::getInstance().currentUser) {
		invalidCmd();
	}
}

void HelpCommand::execute()
{
	System::getInstance().currentUser->help();
}
