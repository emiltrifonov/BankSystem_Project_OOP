#include <iostream>
#include <exception>
#include "CloseTask.h"
#include "Task.h"
#include "MyString.h"
#include "Client.h"
#include "Bank.h"

CloseTask::CloseTask(Client* cPtr, Bank* bPtr, int oldAccID) : cPtr(cPtr), bPtr(bPtr), oldAccID(oldAccID) 
{
	if (!bPtr->isAccountValid(oldAccID, cPtr)) {
		throw std::logic_error("Invalid account");
	}
}

void CloseTask::list() const
{
	//std::cout << "[" << index << "]" <<
	std::cout << "Close - " << cPtr->getFirstName() << " " << cPtr->getLastName()
		<< " wants to close an account with ID " << oldAccID << "." << std::endl;
}

void CloseTask::view() const
{
	std::cout << "Close request from:" << std::endl;
	cPtr->whoami();
	std::cout << "Bank: " << bPtr->getName() << std::endl;
	std::cout << "Account number: " << bPtr->getAccount(oldAccID).getID() << std::endl;
	std::cout << "Account balance: " << bPtr->getAccount(oldAccID).getBalance() << "$" << std::endl;
}

void CloseTask::approve()
{
	bPtr->closeAccount(oldAccID);
	MyString messageText = "Your CLOSE request was approved.";
	//cPtr->addMessage({ messageText, processor });
	cPtr->addMessage(messageText);
}

void CloseTask::disapprove(const MyString& reason)
{
	// Tui cqloto generirane na message trqa e nqkude otdelno
	MyString messageText = "Your CLOSE request was not approved. Reason: ";
	messageText += reason;

	//std::cout << message << std::endl;

	//cPtr->addMessage({messageText, processor});

	cPtr->addMessage(messageText);
}

Task* CloseTask::clone() const
{
	return new CloseTask(*this);
}
