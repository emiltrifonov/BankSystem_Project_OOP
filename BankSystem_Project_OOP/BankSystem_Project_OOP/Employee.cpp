#include <iostream>
#include "Employee.h"

Employee::Employee(const MyString& fN, const MyString& lN, const MyString& egn, const MyString& password, int age) 
	: User(fN, lN, egn, password, age) {}

int Employee::getTaskCount() const {
	return tasks.getSize();
}

void Employee::addTask(Task* t)
{
	tasks.add(t);
}

void Employee::listTasks() const
{
	for (size_t i = 0; i < tasks.getSize(); i++)
	{
		std::cout << "[" << i + 1 << "] ";
		tasks[i]->list();
	}
}

User* Employee::clone() const
{
	return new Employee(*this);
}
