#include "ExitCommand.h"
#include "SystemCommand.h"
#include "System.h"

void ExitCommand::execute()
{
	if (!System::getInstance().currentUser) {
		std::exit(0);
	}
	else {
		System::getInstance().currentUser = nullptr;
	}
}
