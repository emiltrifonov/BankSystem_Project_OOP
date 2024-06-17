#pragma once
#include "SystemCommand.h"
#include "System.h"

class ExitCommand : public SystemCommand {
public:
	void execute() override final;
};