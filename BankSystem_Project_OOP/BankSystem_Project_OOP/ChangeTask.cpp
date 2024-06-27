#include <iostream>
#include <exception>
#include "ChangeTask.h"
#include "System.h"
#include "ChangeNotValidatedException.h"

ChangeTask::ChangeTask(Client* cPtr, Bank* oldBankPtr, Bank* newBankPtr, int oldAccID)
	: cPtr(cPtr), oldBankPtr(oldBankPtr), newBankPtr(newBankPtr), oldAccID(oldAccID) { }

void ChangeTask::list() const
{
	std::cout << "Change - " << cPtr->getFirstName() << " " << cPtr->getLastName()
		<< " wants to join " << newBankPtr->getName() << "." << std::endl;
}

void ChangeTask::view() const
{
	std::cout << "Change request from:" << std::endl;
	std::cout << "Bank: " << oldBankPtr->getName() << std::endl;
	cPtr->whoami();
}

void ChangeTask::approve()
{
	if (canApprove) {
		Account aPtr = oldBankPtr->getAccount(oldAccID);
		newBankPtr->openAccount(aPtr);
		oldBankPtr->closeAccount(oldAccID);
	}
	else {
		throw ChangeNotValidatedException();
	}

	MyString messageText = "Your CHANGE request was approved ";

	cPtr->addMessage({ messageText, (Employee*)System::getInstance().getCurrentUser()});
}

void ChangeTask::disapprove(const MyString& reason)
{
	MyString messageText = "Your CHANGE request was not approved. Reason:";
	messageText += reason;

	cPtr->addMessage({ messageText, (Employee*)System::getInstance().getCurrentUser() });
}

bool ChangeTask::isChangeTask() const
{
	return true;
}

void ChangeTask::validate() const
{
	try {
		oldBankPtr->viewAccount(oldAccID);
	}
	catch (std::exception& e) {
		throw std::logic_error("Validation unsuccessful");
	}

	canApprove = true;
}

Task* ChangeTask::clone() const
{
	return new ChangeTask(*this);
}
