#include <iostream>
#include <exception>
#include "ValidateCommand.h"
#include "System.h"

ValidateCommand::ValidateCommand(int taskIndex, Task* task)
{
	if (!isCurrentUserEmployee() || !task || !task->isChangeTask()) {
		invalidCmd();
	}

	validateIndex(taskIndex);
	this->task = static_cast<ChangeTask*>(task);
}

void ValidateCommand::execute()
{
	task->validate();
}