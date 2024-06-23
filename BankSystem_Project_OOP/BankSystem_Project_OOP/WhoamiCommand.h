#pragma once
#include "System.h"
#include "UserCommand.h"

class WhoamiCommand : public UserCommand {
public:
	WhoamiCommand(System* s);

	void execute() override final;
};