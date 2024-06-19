#include <iostream>
#include <exception>
#include "ListTasksCommand.h"
#include "System.h"

void ListTasksCommand::execute()
{
	Employee* current = static_cast<Employee*>(System::getInstance().currentUser);

	for (size_t i = 0; i < current->tasks.getSize(); i++)
	{
		std::cout << "[" << i + 1 << "] ";
		current->tasks[i]->list();
	}
}
