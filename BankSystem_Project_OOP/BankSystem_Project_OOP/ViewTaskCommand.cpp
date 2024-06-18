#include <iostream>
#include <exception>
#include "ViewTaskCommand.h"
#include "Employee.h"
#include "System.h"

ViewTaskCommand::ViewTaskCommand(int taskIndex) : taskIndex(taskIndex) 
{
	if (!System::getInstance().currentUser->isEmployee()) {
		invalidCmd();
	}

	validateIndex(taskIndex);
}

void ViewTaskCommand::execute()
{
	static_cast<Employee*>(System::getInstance().currentUser)->tasks[taskIndex]->view();
}
