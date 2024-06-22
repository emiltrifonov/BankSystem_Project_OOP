#pragma once
#include "UserCommand.h"
#include "System.h"

class ClientCommand : public UserCommand {
public:
	ClientCommand(System* sPtr);

protected:
	bool isCurrentUserClient() const;
};