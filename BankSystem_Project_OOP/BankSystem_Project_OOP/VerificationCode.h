#pragma once
#include "MyString.h"

class VerificationCode {
public:
	VerificationCode(const MyString& code);

	friend std::ostream& operator<<(std::ostream& os, const VerificationCode& vc);
	bool operator==(const VerificationCode& other) const;

	const MyString& getCode() const;

private:
	const MyString code; // Contains only latin letters and numbers
	const static int codeLen = 3;

	void validate() const;
};