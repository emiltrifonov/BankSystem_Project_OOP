#include "ExitCommand.h"
#include "SystemCommand.h"
#include "System.h"

void ExitCommand::execute()
{
	if (!System::getInstance().currentUser) {
		std::cout << "Exiting the system..." << std::endl;
		std::exit(0);
	}
	else {
		User* u = System::getInstance().currentUser;
		std::cout << u->getFirstName() << " " << u->getLastName() << " logged out successfully!" << std::endl;
		System::getInstance().currentUser = nullptr;
	}
}
