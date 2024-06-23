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
	void whoami() const;

	void addCheque(const Cheque* cheque);

	Collection<Cheque>& getPendingCheques();
	Collection<Cheque>& getRedeemedCheques();

	int getMessagesCount() const;
	const Message& getMessageAt(int index) const;
	void addMessage(const Message& message);

	User* clone() const override final;

private:
	const MyString address;
	Collection<Cheque> pendingCheques;
	Collection<Cheque> redeemedCheques;
	Collection<Message> messages;
};