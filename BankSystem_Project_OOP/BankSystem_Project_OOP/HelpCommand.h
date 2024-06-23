#pragma once
#include "System.h"
#include "Command.h"

class HelpCommand : public Command {
public:
	HelpCommand();

	void execute() override final;
};