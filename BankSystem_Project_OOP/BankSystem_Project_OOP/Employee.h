#pragma once
#include "User.h"
#include "MyString.h"
#include "HeterogeneousContainer.hpp"
#include "Task.h"

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
	int indexCounter = 1;

};