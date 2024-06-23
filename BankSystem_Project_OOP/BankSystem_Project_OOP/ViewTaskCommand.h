#pragma once
#include "EmployeeCommand.h"
#include "System.h"

class ViewTaskCommand : public EmployeeCommand {
public:
	ViewTaskCommand(int taskIndex);

	void execute() override final;

private:
	Task* task = nullptr;
};