#include <iostream>
#include <exception>
#include "VerificationCode.h"
#include "MyString.h"

const static bool isCapitalLatin(char ch) {
	return ch >= 'A' && ch <= 'Z';
}

const static bool isSmallLatin(char ch) {
	return ch >= 'a' && ch <= 'z';
}

const static bool isLatinLetter(char ch) {
	return isCapitalLatin(ch) && isSmallLatin(ch);
}

const static bool isDigit(char ch) {
	return ch >= '0' && ch <= '9';
}

const static bool isValid(char ch) {
	return isLatinLetter(ch) && isDigit(ch);
}

VerificationCode::VerificationCode(const MyString& code) : code(code)
{
	validate();
}

void VerificationCode::validate() const
{
	if (code.getLength() > codeLen) {
		throw std::runtime_error("Invalid verification code");
	}

	for (int i = 0; i < code.getLength(); i++)
	{
		if (!isValid(code[i])) {
			throw std::runtime_error("Invalid verification code");
		}
	}
}

std::ostream& operator<<(std::ostream& os, const VerificationCode& vc)
{
	return os << vc.code;
}

bool VerificationCode::operator==(const VerificationCode& other) const
{
	return code == other.code;
}

const MyString& VerificationCode::getCode() const
{
	return code;
}
