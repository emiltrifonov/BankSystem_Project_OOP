#include <iostream>
#include <exception>
#include "Client.h"

using std::cout;
using std::endl;

Client::Client(const MyString& fN, const MyString& lN, const MyString& egn, const MyString& password, int age, const MyString& address)
    : User(fN, lN, egn, password, age), address(address) {}

void Client::help() const
{
    
}

void Client::addCheque(const Cheque& cheque)
{
    //pendingCheques.push(cheque);
}

void Client::showMessages() const
{
    for (size_t i = 0; i < messages.getSize(); i++)
    {
        std::cout << messages[i] << std::endl;
    }
}

void Client::addMessage(const Message& message)
{
    messages.add(message);
}

bool Client::operator==(const Client& other) const
{
    return egn == other.egn;
}

const MyString& Client::getEGN() const {
    return egn;
}

User* Client::clone() const
{
    return new Client(*this);
}