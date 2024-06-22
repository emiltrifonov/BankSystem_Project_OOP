#pragma once
#include "System.h"
#include "EmployeeCommand.h"

class ListTasksCommand : public EmployeeCommand {
public:
	ListTasksCommand(System* sPtr);

	void execute() override final;
};