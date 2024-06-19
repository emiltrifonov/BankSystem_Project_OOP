#pragma once
#include "Command.h"
#include "System.h"

class EmployeeCommand : public Command {
public:
	EmployeeCommand();

protected:
	bool isCurrentUserEmployee() const;
	void validateIndex(int index) const;
};