#pragma once
#include "System.h"
#include "ClientCommand.h"

class MessagesCommand : public ClientCommand {
public:
	void execute() override final;
};