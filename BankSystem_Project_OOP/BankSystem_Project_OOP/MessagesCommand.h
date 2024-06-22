#pragma once
#include "System.h"
#include "ClientCommand.h"

class MessagesCommand : public ClientCommand {
public:
	MessagesCommand(System* sPtr);

	void execute() override final;
};