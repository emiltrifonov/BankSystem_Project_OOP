#pragma once
#include "System.h"
#include "SystemCommand.h"

class SignupCommand : public SystemCommand {
public:
	SignupCommand();

	void execute() override final;
};