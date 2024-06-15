#include <iostream>
#include "ThirdPartyEmployee.h"

ThirdPartyEmployee::ThirdPartyEmployee(const MyString& fN, const MyString& lN, const MyString& egn, const MyString& password,
	int age) : User(fN, lN, egn, password, age) {}

void ThirdPartyEmployee::sendCheque(double sum, MyString uniqueCode, MyString egn, MyString bankName)
{

}

