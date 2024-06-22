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
	// Task factory probably
	bankPtr->getLeastBusyEmployee(sPtr->banks, sPtr->users)
		->addTask(new CloseTask(static_cast<Client*>(sPtr->currentUser), bankPtr, accID));
}
