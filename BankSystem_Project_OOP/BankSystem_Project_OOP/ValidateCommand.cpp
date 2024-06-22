#include <iostream>
#include <exception>
#include "ValidateCommand.h"
#include "System.h"
#include "Task.h"
#include "ChangeTask.h"

ValidateCommand::ValidateCommand(System* sPtr, int taskIndex) : EmployeeCommand(sPtr, taskIndex)
{
	validateIndex(index);

	Task* t = static_cast<Employee*>(sPtr->currentUser)->tasks[index].get();

	if (t->isChangeTask()) {
		task = static_cast<ChangeTask*>(t);
	}
	else {
		invalidCmd();
	}
}

void ValidateCommand::execute()
{
	task->validate();
}