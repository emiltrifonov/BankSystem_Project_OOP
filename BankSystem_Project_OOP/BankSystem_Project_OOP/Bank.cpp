#include <iostream>
#include "Bank.h"

Bank::Bank(const MyString& name) : name(name) { }

const MyString& Bank::getName() const
{
	return name;
}

Employee* Bank::getLeastBusyEmployee()
{
	if (employees.getSize() == 0) {
		throw std::logic_error("No employess available");
	}

	int currInd = -1;
	int minTasks = INT_MAX;
	for (int i = 0; i < employees.getSize(); i++)
	{
		if (employees[i].getTaskCount() < minTasks) {
			currInd = i;
		}
	}

	return &employees[currInd];
}

const static unsigned getID() {
	static unsigned ID = 100;
	return ID++;
}

void Bank::openAccount(const Client* cPtr)
{
	accounts.add(Account(cPtr, getID()));
}

void Bank::closeAccount(int ID)
{
	for (int i = 0; i < accounts.getSize(); i++)
	{
		if (accounts[i].getID() == ID) {
			accounts.removeAt(i);
			return;
		}
	}

	//throw std::logic_error("Account doesn't exist"); Should probably not throw this
}

bool Bank::isAccountValid(int ID, const Client* cPtr) const
{
	for (int i = 0; i < accounts.getSize(); i++)
	{
		if (accounts[i].getID() == ID && *(accounts[i].getHolder()) == *(cPtr)) {
			return true;
		}
	}

	return false;
}

bool Bank::existsAccount(int accID) const
{
	for (int i = 0; i < accounts.getSize(); i++)
	{
		if (accounts[i].getID() == accID) {
			return true;
		}
	}

	return false;
}

void Bank::addEmployee(const Employee& eRef)
{
	employees.add(eRef);
}