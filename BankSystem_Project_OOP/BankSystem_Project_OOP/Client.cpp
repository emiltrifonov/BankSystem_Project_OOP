#include <iostream>
#include <exception>
#include "Client.h"

using std::cout;
using std::endl;

Client::Client(const MyString& fN, const MyString& lN, const MyString& egn, const MyString& password, int age, const MyString& address)
    : User(fN, lN, egn, password, age), address(address) { }

void Client::help() const
{
    std::cout << "check_avl [bank_name] [account_number] - shows balance in chosen account" << std::endl;

    std::cout << "open [bank_name] - sends request to open new account in chosen bank" << std::endl;

    std::cout << "close [bank_name] [account_number] - sends request to close chosen account" << std::endl;

    std::cout << "redeem [bank_name] [account_number] [verification_code] - redeems cheque in chosen account" << std::endl;

    std::cout << "change [new_bank_name] [current_bank_name] [account_number] - " 
        << "sends request to move chosen account to another bank" << std::endl;

    std::cout << "list [bank_name] - shows all owned accounts in chosen bank" << std::endl;

    std::cout << "messages - shows all received messages in chronological order" << std::endl;

    std::cout << "exit - logs out of the system" << std::endl;
}

void Client::addCheque(const Cheque* cheque)
{
    pendingCheques.add(*cheque);
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

void Client::whoami() const
{
    User::whoami();
    std::cout << "Address: " << address << std::endl;
}

User* Client::clone() const
{
    return new Client(*this);
}
