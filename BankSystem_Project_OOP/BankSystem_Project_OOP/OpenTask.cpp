#include <iostream>
#include <exception>
#include "System.h"
#include "OpenTask.h"
#include "Client.h"

OpenTask::OpenTask(Client* cPtr, Bank* bPtr) : cPtr(cPtr), bPtr(bPtr) { }

void OpenTask::list() const
{
	std::cout << "Open - " << cPtr->getFirstName() << " " << cPtr->getLastName()
		<< " wants to join " << bPtr->getName() << "." << std::endl;
}

void OpenTask::view() const
{
	std::cout << "Open request from:" << std::endl;
	cPtr->whoami();
}

void OpenTask::approve()
{
	bPtr->openAccount(cPtr);
	MyString messageText = "Your OPEN request to bank ";
	messageText += bPtr->getName();
	messageText += " was approved";
	//cPtr->addMessage({ messageText, processor });
	cPtr->addMessage({ messageText, (Employee*)System::getInstance().getCurrentUser() });
}

void OpenTask::disapprove(const MyString& reason)
{
	// Tui cqloto generirane na message trqa e nqkude otdelno
	MyString messageText = "Your OPEN request was not approved. Reason:";
	messageText += reason;

	//cPtr->addMessage({ messageText, processor });
	cPtr->addMessage({ messageText, (Employee*)System::getInstance().getCurrentUser() });
}

Task* OpenTask::clone() const
{
	return new OpenTask(*this);
}
