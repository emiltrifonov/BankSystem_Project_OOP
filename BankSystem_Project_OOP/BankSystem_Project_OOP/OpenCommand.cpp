#include <iostream>
#include <exception>
#include "OpenCommand.h"
#include "ListTasksCommand.h"
#include "OpenTask.h"
#include "Client.h"

OpenCommand::OpenCommand(const MyString& bankName)
{
	bankPtr = System::getInstance().getBank(bankName);

	if (!bankPtr) {
		throw std::logic_error("Bank not found");
	}
}

void OpenCommand::execute()
{
	Employee* ePtr = bankPtr->getLeastBusyEmployee();
	ePtr->addTask(new OpenTask((Client*)(System::getInstance().getCurrentUser()), bankPtr));

	std::cout << "Open request sent to " << ePtr->getFirstName() << " " << ePtr->getLastName()
		<< " from bank \"" << bankPtr->getName() << "\"." << std::endl;
}
