#include <iostream>
#include "ThirdPartyEmployee.h"

ThirdPartyEmployee::ThirdPartyEmployee(const MyString& fN, const MyString& lN, const MyString& egn, const MyString& password,
	int age) : User(fN, lN, egn, password, age) {}

bool ThirdPartyEmployee::isThirdPartyEmployee() const
{
	return true;
}

void ThirdPartyEmployee::help() const
{
	std::cout << "send_cheque [sum] [verification_code] [egn] - sends check to user with matching egn" << std::endl;
	std::cout << "exit - logs out of the system" << std::endl;
}

User* ThirdPartyEmployee::clone() const
{
	return new ThirdPartyEmployee(*this);
}

