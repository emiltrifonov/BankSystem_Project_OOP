#include <iostream>
#include <exception>
#include "ViewTaskCommand.h"
#include "Employee.h"
#include "System.h"

ViewTaskCommand::ViewTaskCommand(System* sPtr, int taskIndex) 
	: EmployeeCommand(sPtr, taskIndex)
{
	validateIndex(index);

	task = ((Employee*)(sPtr->currentUser))->getTaskAt(index);
}

void ViewTaskCommand::execute()
{
	task->view();
}
