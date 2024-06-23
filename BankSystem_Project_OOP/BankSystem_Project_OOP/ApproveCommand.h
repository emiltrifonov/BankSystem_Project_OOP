#pragma once
#include "System.h"
#include "EmployeeCommand.h"

class ApproveCommand : public EmployeeCommand {
public:
	ApproveCommand(int taskIndex);

	void execute() override final;

private:
	Task* task = nullptr;
};