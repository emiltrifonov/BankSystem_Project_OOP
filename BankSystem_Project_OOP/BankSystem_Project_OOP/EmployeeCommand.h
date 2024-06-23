#pragma once
#include "System.h"
#include "UserCommand.h"

class EmployeeCommand : public UserCommand {
public:
	EmployeeCommand() = default;
	EmployeeCommand(int index);

protected:
	int index = -1;

	bool isCurrentUserEmployee() const;
	void validateIndex(int index) const;
};