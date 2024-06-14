#include <iostream>
#include <exception>
#include "Account.h"

Account::Account(const Client* ptr, int id) : holder(ptr), id(id) { }

void Account::addBalance(double toAdd)
{
	if (toAdd <= 0) {
		throw std::logic_error("You can only add a positive sum to your account!");
	}
	else {
		balance += toAdd;
	}
}

int Account::getID() const
{
	return id;
}

double Account::getBalance() const
{
	return balance;
}

const Client* Account::getHolder() const
{
	return holder;
}
