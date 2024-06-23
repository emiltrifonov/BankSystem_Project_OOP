#include <iostream>
#include <exception>
#include "ValidateCommand.h"
#include "System.h"
#include "Task.h"
#include "ChangeTask.h"

ValidateCommand::ValidateCommand(int taskIndex) : EmployeeCommand(taskIndex)
{
	validateIndex(index);

	Task* t = static_cast<Employee*>(System::getInstance().getCurrentUser())->getTaskAt(index);

	// Nope
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
	std::cout << "Validation successful. Request can now be approved." << std::endl;
}