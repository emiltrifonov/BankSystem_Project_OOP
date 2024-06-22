#include <iostream>
#include "EmployeeCommand.h"
#include "System.h"

EmployeeCommand::EmployeeCommand(System* sPtr, int index) : UserCommand(sPtr), index(index - 1)
{
	if (!isCurrentUserEmployee()) {
		invalidCmd();
	}
}

bool EmployeeCommand::isCurrentUserEmployee() const
{
    return sPtr->currentUser->isEmployee();
}

void EmployeeCommand::validateIndex(int index) const
{
	if (index < 0 || index >= static_cast<Employee*>(sPtr->currentUser)->tasks.getSize()) {
		throw std::out_of_range("Index out of range");
	}
}
