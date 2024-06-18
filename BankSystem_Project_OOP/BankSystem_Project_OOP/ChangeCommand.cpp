#include <iostream>
#include <exception>
#include "ChangeCommand.h"
#include "ChangeTask.h"
#include "System.h"
#include "MyString.h"

ChangeCommand::ChangeCommand(const MyString& oldBankName, const MyString& newBankName, int oldAccID) : accID(oldAccID)
{
	oldBankPtr = System::getInstance().getBank(oldBankName);
	newBankPtr = System::getInstance().getBank(newBankName);

	if (!oldBankPtr || !newBankPtr) {
		invalidCmd();
	}
}

void ChangeCommand::execute()
{
	// Task factory probably
	newBankPtr->getLeastBusyEmployee()
		->addTask(new ChangeTask(static_cast<Client*>(System::getInstance().currentUser), oldBankPtr, newBankPtr, accID));
}
