#include <iostream>
#include <exception>
#include "ViewTaskCommand.h"
#include "Employee.h"
#include "System.h"

ViewTaskCommand::ViewTaskCommand(int taskIndex) : taskIndex(taskIndex - 1) 
{
	validateIndex(taskIndex);
}

void ViewTaskCommand::execute()
{
	static_cast<Employee*>(System::getInstance().currentUser)->tasks[taskIndex]->view();
}
