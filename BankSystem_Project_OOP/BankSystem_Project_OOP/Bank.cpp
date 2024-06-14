#include <iostream>
#include "Bank.h"
#include "UniqueID.h"

Bank::Bank(const MyString& name) : name(name) { }

const MyString& Bank::getName() const
{
	return name;
}

void Bank::openAccount(const Client* cPtr)
{
	accounts.push(Account(cPtr, getID()));
}

void Bank::closeAccount(int ID)
{
	for (size_t i = 0; i < accounts.getSize(); i++)
	{
		if (accounts[i].getID() == ID) {
			accounts.popAt(i);
			return;
		}
	}

	//throw std::logic_error("Account doesn't exist"); Should probably not throw this
}

bool Bank::isAccountValid(int ID, const Client* cPtr) const
{
	for (size_t i = 0; i < accounts.getSize(); i++)
	{
		if (accounts[i].getID() == ID && *(accounts[i].getHolder()) == *(cPtr)) {
			return true;
		}
	}

	return false;
}

void Bank::addEmployee(const Employee& eRef)
{
	employees.push(eRef);
}