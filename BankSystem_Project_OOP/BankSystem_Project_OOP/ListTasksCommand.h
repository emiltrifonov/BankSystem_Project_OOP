#pragma once
#include "System.h"
#include "EmployeeCommand.h"
#include "Employee.h"
#include "MyString.h"
#include "EGN.h"

class ListTasksCommand : public EmployeeCommand {
public:
	void execute() override final;
};