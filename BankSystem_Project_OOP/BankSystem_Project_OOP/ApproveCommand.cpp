#include <iostream>
#include <exception>
#include "ApproveCommand.h"
#include "System.h"
#include "Employee.h"
#include "ChangeNotValidatedException.h"

ApproveCommand::ApproveCommand(System* sPtr, int taskIndex) : EmployeeCommand(sPtr, taskIndex)
{
	validateIndex(index);

	task = ((Employee*)(sPtr->currentUser))->getTaskAt(index);
}

void ApproveCommand::execute()
{
	try {
		task->approve();
		((Employee*)(sPtr->currentUser))->removeTaskAt(index);
	}
	catch (ChangeNotValidatedException& e) {
		throw e;
	}
	catch (std::exception& e) {
		((Employee*)(sPtr->currentUser))->removeTaskAt(index);
		throw e;
	}
}
