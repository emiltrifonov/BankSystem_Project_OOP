#include <iostream>
#include "Employee.h"

Employee::Employee(const MyString& fN, const MyString& lN, const MyString& egn, const MyString& password, int age) 
	: User(fN, lN, egn, password, age) {}

void Employee::addTask(Task* t)
{
	tasks.add(t);
}

int Employee::getTaskCount() const
{
	return tasks.getSize();
}

bool Employee::isEmployee() const
{
	return true;
}

User* Employee::clone() const
{
	return new Employee(*this);
}
