#pragma once
#include "User.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "Cheque.h"

class Client : public User {
public:
	//Client() = default;
	Client(const MyString& fN, const MyString& lN, const MyString& egn, const MyString& password, int age, 
		const MyString& address);
	User* clone() const override final;
	void help() const override final;

	void addCheque(const Cheque& cheque);
	//void redeemCheque(const MyString& bankName, int id, const MyString& uniqueCode);

	void addMessage(const MyString& message);

	bool operator==(const Client& other) const;

	const MyString& getFirstName() const;
	const MyString& getLastName() const;

	const MyString& getEGN() const;

private:
	MyString address;
	MyVector<Cheque> pendingCheques;
	MyVector<Cheque> redeemedCheques;
	MyVector<MyString> messages; // Will create class Message with members MyString message and const Employee* ePtrProcessedBy

};