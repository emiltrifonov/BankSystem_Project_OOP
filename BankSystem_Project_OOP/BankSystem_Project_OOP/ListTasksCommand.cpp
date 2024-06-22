#include <iostream>
#include <exception>
#include "ListTasksCommand.h"
#include "System.h"
#include "Employee.h"

ListTasksCommand::ListTasksCommand(System* sPtr) : EmployeeCommand(sPtr, 0)
{
	this->sPtr = sPtr;
}

void ListTasksCommand::execute()
{
	Employee* current = (Employee*)(sPtr->currentUser);

	std::cout << "Tasks count ->" << current->getTaskCount() << "<-" <<std::endl;

	for (int i = 0; i < current->getTaskCount(); i++)
	{
		std::cout << "[" << i + 1 << "] ";
		current->tasks[i]->list();
	}
}
