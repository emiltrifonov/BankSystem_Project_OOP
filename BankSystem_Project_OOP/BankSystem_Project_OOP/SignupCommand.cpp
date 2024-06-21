#include <iostream>
#include <exception>
#include "SignupCommand.h"
#include "System.h"
#include "UserFactory.h"

SignupCommand::SignupCommand()
{
	if (System::getInstance().currentUser) {
		throw std::logic_error("Current user must log out first");
	}
}

void SignupCommand::execute()
{
	System::getInstance().users.add(userFactory());
	std::cout << "User created successfully" << std::endl << std::endl;
}
