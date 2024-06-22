#pragma once
#include "System.h"
#include "Command.h"

class UserCommand : public Command {
public:
	UserCommand(System* sPtr);

private:
	bool isUserCurrentlyLogged() const;
};