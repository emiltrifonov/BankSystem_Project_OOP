#include <iostream>
#include "User.h"
using std::cin;
using std::cout;
using std::endl;

User::User(const MyString& fN, const MyString& lN, const MyString& egn, const MyString& password, int age)
{
	firstName = fN;
	lastName = lN;
	this->egn = egn;
	this->password = password;
	this->age = age;
}

void User::whoami() const
{
	cout << "Name: " << firstName << " " << lastName << endl;
	cout << "EGN: " << egn << endl;
	cout << "Age: " << age << endl;
}