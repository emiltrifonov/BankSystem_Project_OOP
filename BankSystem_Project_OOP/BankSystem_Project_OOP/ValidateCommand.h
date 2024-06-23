#pragma once
#include "System.h"
#include "ChangeTask.h"
#include "EmployeeCommand.h"

class ValidateCommand : public EmployeeCommand {
public:
	ValidateCommand(int taskIndex);

	void execute() override final;

private:
	ChangeTask* task = nullptr;
};