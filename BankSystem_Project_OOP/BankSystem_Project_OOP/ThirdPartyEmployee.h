#pragma once
#include "Client.h"
#include "Cheque.h"
#include "Bank.h"

class ThirdPartyEmployee : public User {
public:
	ThirdPartyEmployee(const MyString& fN, const MyString& lN, const MyString& egn, const MyString& password, int age);

	bool isThirdPartyEmployee() const override final;

	void help() const override final;
	User* clone() const override final;
};