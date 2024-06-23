#pragma once
#include "User.h"
#include "MyString.h"
#include "PolymorphicPtr.hpp"
#include "MyVector.hpp"
#include "Task.h"

class Employee : public User {
public:
	Employee(const MyString& fN, const MyString& lN, const MyString& egn, const MyString& password, int age);

	void whoami() const;

	void addTask(Task* t);
	int getTaskCount() const;
	Task* getTaskAt(int ind);

	void removeTaskAt(int index);

	User* clone() const override final;
	void help() const override final;

private:
	MyVector<PolymorphicPtr<Task>> tasks;
};