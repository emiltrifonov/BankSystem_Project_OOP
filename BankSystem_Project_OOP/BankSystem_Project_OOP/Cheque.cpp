#include <iostream>
#include "Cheque.h"

Cheque::Cheque(const VerificationCode& code, double sum) : verificationCode(code), sum(sum) { }

const MyString& Cheque::getCode() const
{
	return verificationCode.getCode();
}

double Cheque::getSum() const
{
	return sum;
}