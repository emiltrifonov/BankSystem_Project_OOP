#pragma once
#include "UserCommand.h"
#include "System.h"

class ClientCommand : public UserCommand {
public:
	ClientCommand();

protected:
	bool isCurrentUserClient() const;
};