#include <iostream>
#include <exception>
#include "SignupCommand.h"
#include "System.h"
#include "UserFactory.h"

SignupCommand::SignupCommand()
{
	if (System::getInstance().isUserLogged()) {
		throw std::logic_error("Current user must log out first");
	}
}

void SignupCommand::execute()
{
	User* uPtr = userFactory();
	System::getInstance().addUser(uPtr);
	std::cout << "User " << uPtr->getFirstName() << " " << uPtr->getLastName() 
		<< " created successfully!" << std::endl;
}
