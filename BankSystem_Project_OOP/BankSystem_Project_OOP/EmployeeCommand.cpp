#include <iostream>
#include "EmployeeCommand.h"
#include "System.h"

bool EmployeeCommand::isCurrentUserEmployee() const
{
    return System::getInstance().currentUser->isEmployee();
}

void EmployeeCommand::validateIndex(int index) const
{
	if (index < 1 || index > static_cast<Employee*>(System::getInstance().currentUser)->tasks.getSize()) {
		throw std::out_of_range("Index out of range");
	}
}
