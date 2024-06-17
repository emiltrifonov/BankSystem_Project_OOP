#include <iostream>
#include <exception>
#include "DisapproveCommand.h"
#include "System.h"

DisapproveCommand::DisapproveCommand(int taskIndex, const MyString& reason) : reason(reason)
{
	if (!isCurrentUserEmployee()) {
		invalidCmd();
	}

	validateIndex(taskIndex);
}

void DisapproveCommand::execute()
{
	task->disapprove(reason);
}
