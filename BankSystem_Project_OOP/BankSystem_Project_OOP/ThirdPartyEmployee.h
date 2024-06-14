#pragma once
#include "Client.h"
#include "Cheque.h"
#include "Bank.h"

class ThirdPartyEmployee : public User {
public:
	ThirdPartyEmployee(const MyString& fN, const MyString& lN, const MyString& egn, const MyString& password, int age);

	// Unique code contains only latin letters and numbers and is 3 chars long
	void sendCheque(double sum, MyString uniqueCode, MyString egn, MyString bankName);

private:
	const static size_t maxUniqueCodeLen = 3;

};