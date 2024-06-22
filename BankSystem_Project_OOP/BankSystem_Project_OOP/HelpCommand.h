#pragma once
#include "System.h"
#include "Command.h"

class HelpCommand : public Command {
public:
	HelpCommand(System* sPtr);

	void execute() override final;
};