#include <iostream>
#include <exception>
#include "ValidateCommand.h"
#include "System.h"
#include "Task.h"
#include "ChangeTask.h"

ValidateCommand::ValidateCommand(int taskIndex)
{
	validateIndex(taskIndex);;

	Task* t = static_cast<Employee*>(System::getInstance().currentUser)->tasks[taskIndex];

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