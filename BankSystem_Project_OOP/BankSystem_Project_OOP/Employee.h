#pragma once
#include "User.h"
#include "MyString.h"
//#include "HeterogeneousContainer.hpp"
#include "PolymorphicPtr.hpp"
#include "MyVector.hpp"
#include "Task.h"

class Employee : public User {
public:
	Employee(const MyString& fN, const MyString& lN, const MyString& egn, const MyString& password, int age);

	void addTask(Task* t);
	//int getTaskCount() const;

	void whoami() const;

	int getTaskCount() const override { return tasks.getSize(); }

	Task* getTaskAt(int ind) { return tasks[ind].get(); }

	// Commands
	friend class EmployeeCommand;
	friend class ListTasksCommand;
	friend class ViewTaskCommand;
	friend class ApproveCommand;
	friend class DisapproveCommand;
	friend class ValidateCommand;

	friend class OpenCommand;

	MyVector<PolymorphicPtr<Task>> getTasks() const {
		return tasks;
	}

	void removeTaskAt(int index);

	bool isEmployee() const override final;

	User* clone() const override final;
	void help() const override final;

private:
 	//HeterogeneousContainer<Task> tasks;
	MyVector<PolymorphicPtr<Task>> tasks;
	Bank* bank = nullptr;  // To do
	// Employee must know which bank they work for in order to fix the getLeastBusyEmployee() function
};