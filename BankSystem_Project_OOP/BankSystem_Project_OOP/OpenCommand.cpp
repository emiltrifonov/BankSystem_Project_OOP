#include <iostream>
#include <exception>
#include "OpenCommand.h"
#include "ListTasksCommand.h"
#include "OpenTask.h"
#include "Client.h"

OpenCommand::OpenCommand(System* sPtr, const MyString& bankName) : ClientCommand(sPtr)
{
	bankPtr = sPtr->getBank(bankName);

	if (!bankPtr) {
		throw std::logic_error("Bank not found");
	}
}

void OpenCommand::execute()
{
	OpenTask* ot = new OpenTask((Client*)(sPtr->currentUser), bankPtr);
	Employee* ePtr = bankPtr->getLeastBusyEmployee();
	ePtr->addTask(ot);

	std::cout << "Open request sent to " << ePtr->getFirstName() << " " << ePtr->getLastName()
		<< " from bank \"" << bankPtr->getName() << "\"." << std::endl;
}
