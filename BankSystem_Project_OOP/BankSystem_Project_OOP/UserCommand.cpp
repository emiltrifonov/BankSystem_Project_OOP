#include <iostream>
#include <exception>
#include "UserCommand.h"
#include "System.h"

UserCommand::UserCommand()
{
	if (!isUserCurrentlyLogged()) {
		throw std::logic_error("No user is logged in currently!");
	}
}

bool UserCommand::isUserCurrentlyLogged() const
{
	return System::getInstance().getCurrentUser();
}