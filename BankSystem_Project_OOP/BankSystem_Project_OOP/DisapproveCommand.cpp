#include <iostream>
#include <exception>
#include "DisapproveCommand.h"
#include "System.h"

DisapproveCommand::DisapproveCommand(System* sPtr, int taskIndex, const MyString& reason) 
	: reason(reason), EmployeeCommand(sPtr, taskIndex)
{
	validateIndex(index);

	task = ((Employee*)(sPtr->currentUser))->getTaskAt(index);
}

void DisapproveCommand::execute()
{
	try {
		task->disapprove(reason);
		std::cout << "Request denied." << std::endl;
		((Employee*)(sPtr->currentUser))->removeTaskAt(index);
	}
	catch (std::exception& e) {
		((Employee*)(sPtr->currentUser))->removeTaskAt(index);
		throw e;
	}
}
