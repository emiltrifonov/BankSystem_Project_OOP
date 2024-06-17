#include <iostream>
#include "User.h"
#include "MyString.h"
#include "EGN.h"
using std::cin;
using std::cout;
using std::endl;

User::User(const MyString& fN, const MyString& lN, const MyString& egn, const MyString& password, int age)
	: firstName(fN), lastName(lN), egn(egn), password(password), age(age) { }

bool User::isClient() const
{
	return false;
}

bool User::isEmployee() const
{
	return false;
}

bool User::isThirdPartyEmployee() const
{
	return false;
}

const MyString& User::getFirstName() const
{
	return firstName;
}

const MyString& User::getLastName() const
{
	return lastName;
}

const EGN& User::getEGN() const
{
	return egn;
}

void User::whoami() const
{
	cout << "Name: " << firstName << " " << lastName << endl;
	cout << "EGN: " << egn << endl;
	cout << "Age: " << age << endl;
}