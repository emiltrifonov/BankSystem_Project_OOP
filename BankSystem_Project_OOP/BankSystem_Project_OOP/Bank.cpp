#include <iostream>
#include "Bank.h"
#include "System.h"

Bank::Bank(const MyString& name) : name(name) { }

const MyString& Bank::getName() const
{
	return name;
}

const static unsigned getID() {
	static unsigned ID = 100;
	return ID++;
}

Employee* Bank::getLeastBusyEmployee()
{
	int minTasks = INT_MAX;
	Employee* result = nullptr;
	for (int i = 0; i < employees.getSize(); i++)
	{
		Employee* currentEmployee = employees[i];
		if (currentEmployee->getTaskCount() < minTasks) {
			result = currentEmployee;
			minTasks = currentEmployee->getTaskCount();
		}
	}

	if (!result) {
		throw std::logic_error("Bank has no employees");
	}

	return result;
}

void Bank::openAccount(const Client* cPtr)
{
	accounts.add(Account(cPtr, getID()));
}

// For change command when "copying" account from old to new bank
void Bank::openAccount(Account& aPtr) {
	accounts.add(aPtr);
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

	throw std::logic_error("Account doesn't exist");
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

int Bank::getAccountsCount() const
{
	return accounts.getSize();
}

void Bank::viewAccount(int ID) const
{
	for (int i = 0; i < accounts.getSize(); i++)
	{
		if (accounts[i].getID() == ID) {
			accounts[i].getHolder()->whoami();
			std::cout << "Bank: " << name << std::endl;
			std::cout << "Acccount ID: " << accounts[i].getID() << std::endl;
			std::cout << std::endl;
			return;
		}
	}

	throw std::out_of_range("");
}

Account& Bank::getAccountAt(int index)
{
	return accounts[index];
}

Account& Bank::getAccount(int ID)
{
	for (int i = 0; i < accounts.getSize(); i++)
	{
		if (accounts[i].getID() == ID) {
			return accounts[i];
		}
	}

	throw std::logic_error("Account doesn't exist");
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

void Bank::addEmployee(Employee* ePtr)
{
	employees.push(ePtr);
}