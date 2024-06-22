#pragma once
#include "EmployeeCommand.h"
#include "System.h"

class ViewTaskCommand : public EmployeeCommand {
public:
	ViewTaskCommand(System* sPtr, int taskIndex);

	void execute() override final;

private:
	Task* task = nullptr;
};