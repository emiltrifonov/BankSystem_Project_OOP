#include <iostream>
#include <exception>
#include "CloseTask.h"

CloseTask::CloseTask(Client* cPtr, Bank* bPtr, int oldAccID) : cPtr(cPtr), bPtr(bPtr), oldAccID(oldAccID) 
{
	if (!bPtr->isAccountValid(oldAccID, cPtr)) {
		throw std::logic_error("Cannot close invalid account");
	}
}

void CloseTask::list() const
{
	//std::cout << "[" << index << "]" << 
	std::cout << "Close - " << cPtr->getFirstName() << " " << cPtr->getLastName()
		<< " wants to close an account." << std::endl;
}

void CloseTask::view() const
{
	std::cout << "Close request from:" << std::endl;
	cPtr->whoami();
	std::cout << "Bank: " << bPtr->getName() << std::endl;
	std::cout << "Account number: " << bPtr->getAccount(oldAccID).getID() << std::endl;
	std::cout << "Account number: " << bPtr->getAccount(oldAccID).getBalance() << std::endl;
}

void CloseTask::approve()
{
	bPtr->closeAccount(oldAccID);
}

void CloseTask::disapprove(const MyString& reason)
{
	// Tui cqloto generirane na message trqa e nqkude otdelno
	MyString message = "Your CLOSE request was not approved. Reason: ";
	message += reason;

	//std::cout << message << std::endl;

	cPtr->addMessage(message);
}

Task* CloseTask::clone() const
{
	return new CloseTask(*this);
}
