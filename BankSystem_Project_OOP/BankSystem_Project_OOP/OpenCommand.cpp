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
	bankPtr->getLeastBusyEmployee(sPtr->banks, sPtr->users)->addTask(ot);
	Employee* e = bankPtr->getLeastBusyEmployee(sPtr->banks, sPtr->users);

	/*std::cout << "Now employee " << e->getFirstName() << " " << e->getLastName() 
		<< " has " << e->getTaskCount() << " tasks.\n\n";*/

	std::cout << "Open request sent successfully to " 
		<< e->getFirstName() << " " << e->getLastName() 
		<< " - employee of Bank \"" << bankPtr->getName() << "\"" << std::endl;

	/*for (size_t i = 0; i < e->tasks.getSize(); i++)
	{
		e->tasks[i]->list();
	}*/
}
