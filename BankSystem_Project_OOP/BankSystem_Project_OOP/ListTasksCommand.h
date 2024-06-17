#pragma once
#include "System.h"
#include "EmployeeCommand.h"
#include "MyString.h"
#include "EGN.h"

class ListTasksCommand : public EmployeeCommand {
public:
	ListTasksCommand(const EGN& egn);
	ListTasksCommand(Employee& employee);

	void execute() override final;

private:
	Employee* employee;
};