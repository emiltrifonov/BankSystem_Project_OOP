#include <iostream>
#include "ThirdPartyEmployee.h"

ThirdPartyEmployee::ThirdPartyEmployee(const MyString& fN, const MyString& lN, const MyString& egn, const MyString& password,
	int age) : User(fN, lN, egn, password, age) {}

bool ThirdPartyEmployee::isThirdPartyEmployee() const
{
	return true;
}

User* ThirdPartyEmployee::clone() const
{
	return new ThirdPartyEmployee(*this);
}

