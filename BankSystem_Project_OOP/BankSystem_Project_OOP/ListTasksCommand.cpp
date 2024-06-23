#include <iostream>
#include <exception>
#include "ListTasksCommand.h"
#include "System.h"
#include "Employee.h"

void ListTasksCommand::execute()
{
	Employee* current = (Employee*)(System::getInstance().getCurrentUser());

	//std::cout << "Tasks count ->" << current->getTaskCount() << "<-" <<std::endl;

	for (int i = 0; i < current->getTaskCount(); i++)
	{
		std::cout << "[" << i + 1 << "] ";
		current->getTaskAt(i)->list();
	}
}
