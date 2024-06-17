#include <iostream>
#include <exception>
#include "EGN.h"
#include "MyString.h"

EGN::EGN(const MyString& egn) : egn(egn)
{
	validate();
}

bool EGN::operator==(const EGN& other) const
{
	return (egn == other.egn);
}

void EGN::validate() const
{
	if (egn.getLength() != validEgnLength) {
		throw std::logic_error("Invalid EGN");
	}
}

std::ostream& operator<<(std::ostream& os, const EGN& egn)
{
	return os << egn.egn;
}
