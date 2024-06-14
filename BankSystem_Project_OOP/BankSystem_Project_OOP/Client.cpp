#include <iostream>
#include <exception>
#include "Client.h"

using std::cout;
using std::endl;

Client::Client(const MyString& fN, const MyString& lN, const MyString& egn, const MyString& password, int age, const MyString& address)
    : User(fN, lN, egn, password, age), address(address) {}

User* Client::clone() const
{
    return new Client(*this);
}

void Client::help() const
{
    
}

void Client::addCheque(const Cheque& cheque)
{
    //pendingCheques.push(cheque);
}

void Client::addMessage(const MyString& message)
{
    messages.push(message);
}

bool Client::operator==(const Client& other) const
{
    return egn == other.egn;
}

const MyString& Client::getFirstName() const
{
    return firstName;
}

const MyString& Client::getLastName() const
{
    return lastName;
}

const MyString& Client::getEGN() const {
    return egn;
}