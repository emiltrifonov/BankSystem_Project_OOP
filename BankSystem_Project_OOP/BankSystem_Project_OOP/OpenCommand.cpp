#include <iostream>
#include <exception>
#include "OpenCommand.h"
#include "OpenTask.h"
#include "Client.h"

OpenCommand::OpenCommand(const MyString& bankName)
{
	bankPtr = System::getInstance().getBank(bankName);

	if (!bankPtr) {
		invalidCmd();
	}
}

void OpenCommand::execute()
{
	OpenTask* ot = new OpenTask(static_cast<Client*>(System::getInstance().currentUser), bankPtr);
	bankPtr->getLeastBusyEmployee()->addTask(ot);
	std::cout << "Now employee has " << bankPtr->getLeastBusyEmployee()->getTaskCount() << " tasks.\n\n";
	std::cout << "Open request sent successfully to Bank \"" << bankPtr->getName() << "\"" << std::endl;
}
