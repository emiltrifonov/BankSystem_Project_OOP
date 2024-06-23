#pragma once
#include "System.h"
#include "UserCommand.h"

class WhoamiCommand : public UserCommand {
public:
	void execute() override final;
};