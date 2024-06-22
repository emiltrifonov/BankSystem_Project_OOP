#pragma once
#include "System.h"
#include "EmployeeCommand.h"
#include "MyString.h"

class DisapproveCommand : public EmployeeCommand {
public:
	DisapproveCommand(System* sPtr, int taskIndex, const MyString& reason);

	void execute() override final;

private:
	Task* task = nullptr;
	const MyString reason;
};
