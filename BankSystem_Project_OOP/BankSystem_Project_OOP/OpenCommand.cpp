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
	// Task factory probably
	bankPtr->getLeastBusyEmployee()->addTask(new OpenTask(static_cast<Client*>(System::getInstance().currentUser), bankPtr));
}
