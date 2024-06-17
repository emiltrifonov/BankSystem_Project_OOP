#pragma once
#include <stdio.h>
#include "MyString.h"
#include "VerificationCode.h"

class Cheque {
public:
	Cheque(const VerificationCode& code, double sum);
	const MyString& getCode() const;
	double getSum() const;

private:
	const VerificationCode verificationCode;
	const double sum;
};