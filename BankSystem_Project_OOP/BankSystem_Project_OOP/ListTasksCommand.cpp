#include <iostream>
#include <exception>
#include "ListTasksCommand.h"
#include "System.h"

void ListTasksCommand::execute()
{
	Employee* current = static_cast<Employee*>(System::getInstance().currentUser);

	std::cout << "Tasks count ->" << current->getTaskCount() << "<-" <<std::endl;

	for (int i = 0; i < current->getTaskCount(); i++)
	{
		std::cout << "[" << i + 1 << "] ";
		current->tasks[i]->list();
	}
}
