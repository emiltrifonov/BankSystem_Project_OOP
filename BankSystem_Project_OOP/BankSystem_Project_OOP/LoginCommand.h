#pragma once
#include "System.h"
#include "SystemCommand.h"
#include "Mystring.h"

class LoginCommand : public SystemCommand {
public:
	LoginCommand(System* sPtr);

	void execute() override final;
};