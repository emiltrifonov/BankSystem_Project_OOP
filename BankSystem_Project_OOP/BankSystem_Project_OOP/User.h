#pragma once
#include "MyString.h"

class User {
public:
	User() = default;
	User(const MyString& fN, const MyString& lN, const MyString& egn, const MyString& password, int age);
	void whoami() const;
	virtual void help() const = 0;
	virtual User* clone() const = 0;
	//void exit() const; // Probably will be a function in System and not in here

	virtual ~User() = default;

protected:
	MyString firstName;
	MyString lastName;
	MyString egn;
	MyString password;
	int age;
};