#include <iostream>
#include "Employee.h"

Employee::Employee(const MyString& fN, const MyString& lN, const MyString& egn, const MyString& password, int age) 
	: User(fN, lN, egn, password, age) {}

void Employee::addTask(Task* t)
{
	tasks.push(t);
}

void Employee::whoami() const
{
	User::whoami();

	std::cout << "Tasks: " << tasks.getSize() << std::endl;
}

//int Employee::getTaskCount() const
//{
//	return tasks.getSize();
//}

void Employee::removeTaskAt(int index)
{
	tasks.popAt(index);
}

bool Employee::isEmployee() const
{
	return true;
}

User* Employee::clone() const
{
	return new Employee(*this);
}

void Employee::help() const
{
	std::cout << "tasks - shows list of assigned tasks" << std::endl;

	std::cout << "view [task_id] - shows details about chosen task" << std::endl;

	std::cout << "approve [task_id] - approves chosen request" << std::endl;

	std::cout << "disapprove [task_id] - denies chosen request" << std::endl;

	std::cout << "validate [task_id] - validates data given through change task" << std::endl;

	std::cout << "exit - logs out of the system" << std::endl;
}
