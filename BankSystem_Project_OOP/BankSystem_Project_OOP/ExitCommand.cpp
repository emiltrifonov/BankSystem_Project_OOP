#include "ExitCommand.h"
#include "SystemCommand.h"
#include "System.h"

ExitCommand::ExitCommand(System* sPtr)
{
	this->sPtr = sPtr;
}

void ExitCommand::execute()
{
	if (!sPtr->currentUser) {
		std::cout << "Exiting the system..." << std::endl;
		std::exit(0);
	}
	else {
		User* u = sPtr->currentUser;
		std::cout << u->getFirstName() << " " << u->getLastName() << " logged out successfully!" << std::endl;
		sPtr->currentUser = nullptr;
	}
}
