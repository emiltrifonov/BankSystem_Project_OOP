#include <iostream>
#include <exception>
#include "ChangeCommand.h"
#include "ChangeTask.h"
#include "System.h"
#include "MyString.h"

ChangeCommand::ChangeCommand(System* sPtr, const MyString& newBankName, const MyString& currentBankName, int oldAccID)
	: ClientCommand(sPtr), accID(oldAccID)
{
	currenBankPtr = sPtr->getBank(currentBankName);
	newBankPtr = sPtr->getBank(newBankName);

	if (!currenBankPtr || !newBankPtr) {
		invalidCmd();
	}
}

void ChangeCommand::execute()
{
	// Task factory probably
	newBankPtr->getLeastBusyEmployee(sPtr->banks, sPtr->users)
		->addTask(new ChangeTask(static_cast<Client*>(sPtr->currentUser), currenBankPtr, newBankPtr, accID));
}
