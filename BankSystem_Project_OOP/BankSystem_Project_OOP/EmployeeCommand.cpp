#include <iostream>
#include "EmployeeCommand.h"
#include "System.h"

EmployeeCommand::EmployeeCommand(int index) : index(index - 1)
{
	if (!isCurrentUserEmployee()) {
		invalidCmd();
	}
}

bool EmployeeCommand::isCurrentUserEmployee() const
{
    return System::getInstance().getCurrentUser()->isEmployee();
}

void EmployeeCommand::validateIndex(int index) const
{
	if (index < 0 || index >= static_cast<Employee*>(System::getInstance().getCurrentUser())->getTaskCount()) {
		throw std::out_of_range("Index out of range");
	}
}
