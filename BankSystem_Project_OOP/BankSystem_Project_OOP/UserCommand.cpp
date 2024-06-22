#include <iostream>
#include <exception>
#include "UserCommand.h"
#include "System.h"

UserCommand::UserCommand(System* sPtr)
{
	this->sPtr = sPtr;

	if (!isUserCurrentlyLogged()) {
		throw std::logic_error("No user is logged in currently!");
	}
}

bool UserCommand::isUserCurrentlyLogged() const
{
	return sPtr->currentUser;
}