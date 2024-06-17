#pragma once
#include "Command.h"
#include "System.h"

class EmployeeCommand : public Command {
protected:
	bool isCurrentUserEmployee() const;
	void validateIndex(int index) const;
};