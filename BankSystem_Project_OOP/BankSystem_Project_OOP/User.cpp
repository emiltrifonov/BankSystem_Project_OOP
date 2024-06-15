#include <iostream>
#include "User.h"
using std::cin;
using std::cout;
using std::endl;

User::User(const MyString& fN, const MyString& lN, const MyString& egn, const MyString& password, int age)
	: firstName(fN), lastName(lN), egn(egn), password(password), age(age) { }

const MyString& User::getFirstName() const
{
	return firstName;
}

const MyString& User::getLastName() const
{
	return lastName;
}

void User::whoami() const
{
	cout << "Name: " << firstName << " " << lastName << endl;
	cout << "EGN: " << egn << endl;
	cout << "Age: " << age << endl;
}