#pragma once
#include <iostream>
#include "MyString.h"

class EGN {
public:
	EGN(const MyString& egn);

	bool operator==(const EGN& other) const;

	friend std::ostream& operator<<(std::ostream& os, const EGN& egn);

private:
	const MyString egn;
	const static int validEgnLength = 10;

	void validate() const;
};