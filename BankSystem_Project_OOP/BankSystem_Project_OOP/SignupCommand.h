#pragma once
#include "System.h"
#include "SystemCommand.h"

class SignupCommand : public SystemCommand {
public:
	SignupCommand(System* sPtr);

	void execute() override final;
};