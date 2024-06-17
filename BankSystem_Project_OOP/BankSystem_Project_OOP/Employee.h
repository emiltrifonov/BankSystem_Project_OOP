#pragma once
#include "User.h"
#include "MyString.h"
#include "HeterogeneousContainer.hpp"
#include "Task.h"

class Employee : public User {
public:
	Employee(const MyString& fN, const MyString& lN, const MyString& egn, const MyString& password, int age);

	void addTask(Task* t);
	int getTaskCount() const;

	// Commands
	friend class EmployeeCommand;
	friend class ListTasksCommand;
	friend class ViewTaskCommand;
	friend class ApproveCommand;
	friend class DisapproveCommand;
	friend class ValidateCommand;

	bool isEmployee() const override final;

	User* clone() const override final;
	void help() const override final {}

private:
	HeterogeneousContainer<Task> tasks;
	int indexCounter = 1;
};