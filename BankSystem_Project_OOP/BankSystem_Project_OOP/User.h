#pragma once
#include "MyString.h"
#include "EGN.h"

class User {
public:
	User(const MyString& fN, const MyString& lN, const MyString& egn, const MyString& password, int age);
	
	void whoami() const;
	virtual void help() const = 0;
	virtual User* clone() const = 0;

	// Tova SHTE se mahne ToT
	virtual bool isClient() const;
	virtual bool isEmployee() const;
	virtual bool isThirdPartyEmployee() const;

	const MyString& getFirstName() const;
	const MyString& getLastName() const;
	const EGN& getEGN() const;
	const MyString& getPassword() const;

	virtual ~User() = default;

protected:
	const MyString firstName;
	const MyString lastName;
	const EGN egn;
	const MyString password;
	const int age;
};