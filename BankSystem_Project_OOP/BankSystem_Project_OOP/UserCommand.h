#pragma once
#include "System.h"
#include "Command.h"

class UserCommand : public Command {
public:
	UserCommand();

private:
	bool isUserCurrentlyLogged() const;
};