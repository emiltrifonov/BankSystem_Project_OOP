#pragma once
#include "System.h"
#include "SystemCommand.h"

class SignupCommand : public SystemCommand { // To do after User factory is created
public:
	SignupCommand();

	void execute() override final;
};