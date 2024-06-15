#pragma once
#include <stdio.h>
#include "User.h"
#include "Task.h"
#include "HeterogeneousContainer.hpp"

class Employee : public User {
public:
	Employee(const MyString& fN, const MyString& lN, const MyString& egn, const MyString& password, int age);
	/*void open();
	void close();
	void change();
	void listTasks() const;*/
	int getTaskCount() const;
	void addTask(Task* t);

	void listTasks() const;

	User* clone() const override final;
	void help() const override final {}

private:
	HeterogeneousContainer<Task> tasks;
	int taskCount = 0;
};