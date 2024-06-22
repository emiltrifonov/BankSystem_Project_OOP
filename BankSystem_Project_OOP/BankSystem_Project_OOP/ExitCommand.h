#pragma once
#include "SystemCommand.h"
#include "System.h"

class ExitCommand : public SystemCommand {
public:
	ExitCommand(System* sPtr);

	void execute() override final;
};