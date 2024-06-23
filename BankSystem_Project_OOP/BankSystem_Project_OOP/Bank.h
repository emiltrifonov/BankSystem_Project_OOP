#pragma once
#include "MyString.h"
#include "MyVector.hpp"
#include "Collection.hpp"
#include "Client.h"
#include "Employee.h"
#include "Account.h"

class Bank {
public:
	Bank(const MyString& name);

	const MyString& getName() const;

	Employee* getLeastBusyEmployee();

	void openAccount(const Client* cPtr);
	void openAccount(Account& aPtr);
	void closeAccount(int ID);
	bool isAccountValid(int ID, const Client* cPtr) const;

	int getAccountsCount() const;
	void viewAccount(int ID) const {
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
	Account& getAccountAt(int index);
	Account& getAccount(int ID) {
		for (int i = 0; i < accounts.getSize(); i++)
		{
			if (accounts[i].getID() == ID) {
				return accounts[i];
			}
		}

		throw std::logic_error("Account doesn't exist");
	}

	bool existsAccount(int accID) const;

	void addEmployee(Employee* ePtr);

private:
	const MyString name;
	// Does not manage memory! (System manages all the users, here we only keep pointers to the bank's employees)
	MyVector<Employee*> employees;
	Collection<Account> accounts;
};