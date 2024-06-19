#include <iostream>
#include <exception>
#include "ApproveCommand.h"
#include "System.h"

ApproveCommand::ApproveCommand(int taskIndex)
{
	validateIndex(taskIndex);
}

void ApproveCommand::execute()
{
	task->approve();
}
