#include <iostream>
#include <exception>
#include "CloseCommand.h"
#include "CloseTask.h"
#include "Client.h"

CloseCommand::CloseCommand(const MyString& bankName, int accID) : accID(accID)
{
	bankPtr = System::getInstance().getBank(bankName);

	if (!bankPtr) {
		invalidCmd();
	}
}

void CloseCommand::execute()
{
	Employee* ePtr = bankPtr->getLeastBusyEmployee();
	// Task factory probably
	ePtr->addTask(new CloseTask(static_cast<Client*>(System::getInstance().getCurrentUser()), bankPtr, accID));

	std::cout << "Close request sent to " << ePtr->getFirstName() << " " << ePtr->getLastName()
		<< " from bank \"" << bankPtr->getName() << "\"." << std::endl;
}
