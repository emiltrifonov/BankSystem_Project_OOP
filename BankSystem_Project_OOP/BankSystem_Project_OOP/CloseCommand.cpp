#include <iostream>
#include <exception>
#include "CloseCommand.h"
#include "CloseTask.h"
#include "Client.h"

CloseCommand::CloseCommand(System* sPtr, const MyString& bankName, int accID) : ClientCommand(sPtr), accID(accID)
{
	bankPtr = sPtr->getBank(bankName);

	if (!bankPtr) {
		invalidCmd();
	}
}

void CloseCommand::execute()
{
	Employee* ePtr = bankPtr->getLeastBusyEmployee();
	// Task factory probably
	ePtr->addTask(new CloseTask(static_cast<Client*>(sPtr->currentUser), bankPtr, accID));

	std::cout << "Close request sent to " << ePtr->getFirstName() << " " << ePtr->getLastName()
		<< " from bank \"" << bankPtr->getName() << "\"." << std::endl;
}
