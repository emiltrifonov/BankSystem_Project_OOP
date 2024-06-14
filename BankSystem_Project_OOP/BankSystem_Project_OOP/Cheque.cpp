#include <iostream>
#include "Cheque.h"

Cheque::Cheque(const MyString& code, double sum) : uniqueCode(code), sum(sum) { }

const MyString& Cheque::getCode() const
{
	return uniqueCode;
}

double Cheque::getSum() const
{
	return sum;
}