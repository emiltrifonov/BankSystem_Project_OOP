#include <iostream>
#include <exception>
#include "Client.h"

using std::cout;
using std::endl;

Client::Client(const MyString& fN, const MyString& lN, const MyString& egn, const MyString& password, int age, const MyString& address)
    : User(fN, lN, egn, password, age), address(address) {}

void Client::addCheque(const Cheque& cheque)
{
    pendingCheques.add(cheque);
}

bool Client::isClient() const
{
    return true;
}

//void Client::addMessage(const Message& message)
//{
//    messages.add(message);
//}

bool Client::operator==(const Client& other) const
{
    return egn == other.egn;
}

User* Client::clone() const
{
    return new Client(*this);
}
