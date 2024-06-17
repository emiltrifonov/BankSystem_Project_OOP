#pragma once
#include "Command.h"
#include "System.h"

class ClientCommand : public Command {
public:
	ClientCommand();

protected:
	bool isCurrentUserClient() const;
};