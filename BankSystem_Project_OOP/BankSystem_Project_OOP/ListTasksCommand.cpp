#include <iostream>
#include <exception>
#include "ListTasksCommand.h"
#include "System.h"

ListTasksCommand::ListTasksCommand(const EGN& egn)
{
	int usersCount = System::getInstance().users.getSize();

	for (int i = 0; i < usersCount; i++)
	{
		User* current = System::getInstance().users[i];
		if (current->getEGN() == egn) {
			if (current->isEmployee()) {
				employee = static_cast<Employee*>(current);
				return;
			}
			throw std::logic_error("Invalid employee");
		}
	}

	throw std::logic_error("Invalid employee");
}

ListTasksCommand::ListTasksCommand(Employee& employee)
{
	this->employee = &employee;
}

void ListTasksCommand::execute()
{
	for (size_t i = 0; i < employee->tasks.getSize(); i++)
	{
		std::cout << "[" << i + 1 << "] ";
		employee->tasks[i]->list();
	}
}
