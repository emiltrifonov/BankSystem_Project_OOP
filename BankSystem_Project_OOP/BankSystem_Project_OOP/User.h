#pragma once
#include "MyString.h"

class User {
public:
	User(const MyString& fN, const MyString& lN, const MyString& egn, const MyString& password, int age);
	void whoami() const;
	virtual void help() const = 0;
	virtual User* clone() const = 0;
	//void exit() const; // Probably will be a function in System and not in here

	const MyString& getFirstName() const;
	const MyString& getLastName() const;

	virtual ~User() = default;

protected:
	const MyString firstName;
	const MyString lastName;
	const MyString egn;
	const MyString password;
	const int age;
};