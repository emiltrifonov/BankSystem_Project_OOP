#pragma once
#include "System.h"
#include "EmployeeCommand.h"

class ListTasksCommand : public EmployeeCommand {
public:
	void execute() override final;
};