#include <iostream>
#include <exception>
#include "ChangeCommand.h"
#include "ChangeTask.h"
#include "System.h"
#include "MyString.h"

ChangeCommand::ChangeCommand(const MyString& newBankName, const MyString& currentBankName, int oldAccID)
	: accID(oldAccID)
{
	currenBankPtr = System::getInstance().getBank(currentBankName);
	newBankPtr = System::getInstance().getBank(newBankName);

	if (!currenBankPtr || !newBankPtr) {
		invalidCmd();
	}
}

void ChangeCommand::execute()
{
	Employee* ePtr = newBankPtr->getLeastBusyEmployee();
	
	ePtr->addTask(new ChangeTask((Client*)(System::getInstance().getCurrentUser()), currenBankPtr, newBankPtr, accID));

	std::cout << "Change request sent to " << ePtr->getFirstName() << " " << ePtr->getLastName() 
		<< " from bank \"" << newBankPtr->getName() << "\"." << std::endl;
}
