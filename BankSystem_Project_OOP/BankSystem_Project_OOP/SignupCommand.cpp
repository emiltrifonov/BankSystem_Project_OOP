#include <iostream>
#include <exception>
#include "SignupCommand.h"
#include "System.h"
#include "UserFactory.h"

SignupCommand::SignupCommand(System* sPtr)
{
	this->sPtr = sPtr;

	if (sPtr->currentUser) {
		throw std::logic_error("Current user must log out first");
	}
}

void SignupCommand::execute()
{
	User* u = userFactory(sPtr);
	sPtr->users.push(u);
	std::cout << "User " << u->getFirstName() << " " << u->getLastName() 
		<< " created successfully!" << std::endl;
}
