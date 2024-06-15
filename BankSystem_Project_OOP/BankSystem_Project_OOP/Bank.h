#pragma once
#include <stdio.h>
#include "MyString.h"
#include "MyVector.hpp"
#include "Collection.hpp"
#include "Client.h"
#include "Employee.h"
#include "Account.h"

class Bank {
public:
	Bank(const MyString& name);

	/*friend class OpenTask;
	friend class CloseTask;
	friend class ChangeTask;*/

	const MyString& getName() const;

	void openAccount(const Client* cPtr);
	void closeAccount(int ID);
	bool isAccountValid(int ID, const Client* cPtr) const;

	void viewAllAccounts() const { // For testing
		for (size_t i = 0; i < accounts.getSize(); i++)
		{
			accounts[i].getHolder()->whoami();
			std::cout << "Bank: "<< name << std::endl;
			std::cout << "Acccount ID: " << accounts[i].getID() << std::endl;
			std::cout << std::endl;
		}
	}

	void viewAccount(int ID) const {
		for (size_t i = 0; i < accounts.getSize(); i++)
		{
			if (accounts[i].getID() == ID) {
				accounts[i].getHolder()->whoami();
				std::cout << "Bank: " << name << std::endl;
				std::cout << "Acccount ID: " << accounts[i].getID() << std::endl;
				std::cout << std::endl;
			}
		}
	}

	const Account& getAccount(int ID) const {
		for (size_t i = 0; i < accounts.getSize(); i++)
		{
			if (accounts[i].getID() == ID) {
				return accounts[i];
			}
		}

		throw std::logic_error("Account doesn't exist");
	}

	void addEmployee(const Employee& eRef);

private:
	const MyString name;
	Collection<Employee> employees;
	Collection<Account> accounts;

	//void addEmployee(const Employee& eRef);
};