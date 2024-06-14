#pragma once
#include <stdio.h>
#include "MyString.h"

class Cheque {
public:
	Cheque() = default;
	Cheque(const MyString& code, double sum);
	const MyString& getCode() const;
	double getSum() const;

private:
	MyString uniqueCode;
	double sum = 0;
};