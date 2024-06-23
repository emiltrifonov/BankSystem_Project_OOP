#include <iostream>
#include <exception>
#include "ViewTaskCommand.h"
#include "Employee.h"
#include "System.h"

ViewTaskCommand::ViewTaskCommand(int taskIndex) 
	: EmployeeCommand(taskIndex)
{
	validateIndex(index);

	task = ((Employee*)(System::getInstance().getCurrentUser()))->getTaskAt(index);
}

void ViewTaskCommand::execute()
{
	task->view();
}
