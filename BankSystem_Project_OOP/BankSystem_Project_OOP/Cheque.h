#pragma once
#include <stdio.h>
#include "MyString.h"

class Cheque {
public:
	Cheque(const MyString& code, double sum);
	const MyString& getCode() const;
	double getSum() const;

private:
	const MyString uniqueCode;
	const double sum;
};