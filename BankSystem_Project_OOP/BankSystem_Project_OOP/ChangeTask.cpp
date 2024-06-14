#include <iostream>
#include <exception>
#include "ChangeTask.h"

ChangeTask::ChangeTask(Client* cPtr, Bank* oldBankPtr, Bank* newBankPtr, int oldAccID)
	: cPtr(cPtr), oldBankPtr(oldBankPtr), newBankPtr(newBankPtr), oldAccID(oldAccID) { }

void ChangeTask::list() const
{
	std::cout << "Change - " << cPtr->getFirstName() << " " << cPtr->getLastName()
		<< " wants to join " << newBankPtr->getName() << "." << std::endl;
}

void ChangeTask::view() const
{
	std::cout << "Open request from:" << std::endl;
	std::cout << "Bank: " << oldBankPtr->getName() << std::endl;
	cPtr->whoami();
}

void ChangeTask::approve()
{
	if (canApprove) {
		oldBankPtr->closeAccount(oldAccID);
		newBankPtr->openAccount(cPtr);
	}
	else {
		throw std::logic_error("Cannot proceed - please make sure the user is real by asking the bank!");
	}
}

void ChangeTask::disapprove(const MyString& reason)
{
	cPtr->addMessage(reason);
}

void ChangeTask::validate() const
{
	oldBankPtr->viewAccount(oldAccID);

	canApprove = true;
}

Task* ChangeTask::clone() const
{
	return new ChangeTask(*this);
}
