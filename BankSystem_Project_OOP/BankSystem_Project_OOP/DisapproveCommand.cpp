#include <iostream>
#include <exception>
#include "DisapproveCommand.h"
#include "System.h"

DisapproveCommand::DisapproveCommand(int taskIndex, const MyString& reason) 
	: reason(reason), EmployeeCommand(taskIndex)
{
	validateIndex(index);

	task = ((Employee*)(System::getInstance().getCurrentUser()))->getTaskAt(index);
}

void DisapproveCommand::execute()
{
	try {
		task->disapprove(reason);
		std::cout << "Request denied." << std::endl;
		((Employee*)(System::getInstance().getCurrentUser()))->removeTaskAt(index);
	}
	catch (std::exception& e) {
		((Employee*)(System::getInstance().getCurrentUser()))->removeTaskAt(index);
		throw e;
	}
}
