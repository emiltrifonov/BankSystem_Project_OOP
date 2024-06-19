#include <iostream>
#include <exception>
#include "SignupCommand.h"
#include "System.h"
#include "UserFactory.h"

SignupCommand::SignupCommand()
{
	if (System::getInstance().currentUser) {
		invalidCmd();
	}
}

void SignupCommand::execute()
{
	System::getInstance().users.add(userFactory());
}
