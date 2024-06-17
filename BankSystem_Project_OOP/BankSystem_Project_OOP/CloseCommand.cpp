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
	// Task factory probably
	bankPtr->getLeastBusyEmployee()
		->addTask(new CloseTask(static_cast<Client*>(System::getInstance().currentUser), bankPtr, accID));
}
