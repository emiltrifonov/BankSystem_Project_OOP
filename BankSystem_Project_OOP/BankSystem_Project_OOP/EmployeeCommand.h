#pragma once
#include "UserCommand.h"
#include "System.h"

class EmployeeCommand : public UserCommand {
public:
	EmployeeCommand();

protected:
	bool isCurrentUserEmployee() const;
	void validateIndex(int index) const;
};