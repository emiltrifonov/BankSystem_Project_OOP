#include "ExitCommand.h"
#include "SystemCommand.h"
#include "System.h"

void ExitCommand::execute()
{
	if (!System::getInstance().isUserLogged()) {
		std::cout << "Exiting the system..." << std::endl;
		System::getInstance().exitSystem();
	}
	else {
		User* u = System::getInstance().getCurrentUser();
		std::cout << u->getFirstName() << " " << u->getLastName() << " logged out" << std::endl;
		System::getInstance().logout();
	}
}
