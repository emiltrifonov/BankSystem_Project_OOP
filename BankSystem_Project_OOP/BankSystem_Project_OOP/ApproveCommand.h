#pragma once
#include "System.h"
#include "EmployeeCommand.h"

class ApproveCommand : public EmployeeCommand {
public:
	ApproveCommand(System* sPtr, int taskIndex);

	void execute() override final;

private:
	Task* task = nullptr;
};