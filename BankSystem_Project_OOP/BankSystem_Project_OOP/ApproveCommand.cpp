#include <iostream>
#include <exception>
#include "ApproveCommand.h"
#include "System.h"
#include "Employee.h"
#include "ChangeNotValidatedException.h"

ApproveCommand::ApproveCommand(int taskIndex) : EmployeeCommand(taskIndex)
{
	validateIndex(index);

	task = ((Employee*)(System::getInstance().getCurrentUser()))->getTaskAt(index);
}

void ApproveCommand::execute()
{
	try {
		task->approve();
		std::cout << "Request approved." << std::endl;
		((Employee*)(System::getInstance().getCurrentUser()))->removeTaskAt(index);
	}
	catch (ChangeNotValidatedException& e) {
		throw e;
	}
	catch (std::exception& e) {
		((Employee*)(System::getInstance().getCurrentUser()))->removeTaskAt(index);
		throw e;
	}
}
