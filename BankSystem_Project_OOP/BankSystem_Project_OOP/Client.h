#pragma once
#include "User.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "Collection.hpp"
#include "Message.h"
#include "Cheque.h"

class Client : public User {
public:
	Client(const MyString& fN, const MyString& lN, const MyString& egn, const MyString& password, int age, 
		const MyString& address);
	void help() const override final;

	void addCheque(const Cheque& cheque);
	//void redeemCheque(const MyString& bankName, int id, const MyString& uniqueCode);

	void showMessages() const;
	//void addMessage(const Message& message);
	void addMessage(const MyString& message) {
		messages.push(message);
	}

	bool operator==(const Client& other) const;

	const MyString& getEGN() const;

	User* clone() const override final;

private:
	const MyString address;
	Collection<Cheque> pendingCheques;
	Collection<Cheque> redeemedCheques;
	//Collection<Message> messages;
	MyVector<MyString> messages; // Temporary
};