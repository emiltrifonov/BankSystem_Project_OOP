#pragma once
#include "MyString.h"

class User {
public:
	void whoami() const;
	virtual void help() const = 0;
	//void exit() const; // Probably will be a function in System and not in here

protected:
	MyString firstName;
	MyString lastName;
	MyString egn;
	MyString password;
	int age;
};