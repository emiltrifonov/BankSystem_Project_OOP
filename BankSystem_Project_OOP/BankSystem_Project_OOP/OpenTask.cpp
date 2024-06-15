#include <iostream>
#include "OpenTask.h"
#include "Client.h"

OpenTask::OpenTask(Client* cPtr, Bank* bPtr) : cPtr(cPtr), bPtr(bPtr) { }

void OpenTask::list() const
{
	//std::cout << "[" << index << "]" <<
	std::cout << "Open - " << cPtr->getFirstName() << " " << cPtr->getLastName()
		<< " wants to create an account." << std::endl;
}

void OpenTask::view() const
{
	std::cout << "Open request from:" << std::endl;
	cPtr->whoami();
}

void OpenTask::approve()
{
	bPtr->openAccount(cPtr);
}

void OpenTask::disapprove(const MyString& reason)
{
	// Tui cqloto generirane na message trqa e nqkude otdelno
	MyString messageText = "Your OPEN request was not approved. Reason: ";
	messageText += reason;

	//cPtr->addMessage();
}

Task* OpenTask::clone() const
{
	return new OpenTask(*this);
}
