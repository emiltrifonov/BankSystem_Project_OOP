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

	/*friend class OpenTask;
	friend class CloseTask;
	friend class ChangeTask;*/

	const MyString& getName() const;

	//Employee* getLeastBusyEmployee(MyVector<PolymorphicPtr<User>>&);
	Employee* getLeastBusyEmployee();

	void openAccount(const Client* cPtr);
	void closeAccount(int ID);
	bool isAccountValid(int ID, const Client* cPtr) const;

	//
	friend class ListAccountsCommand;
	friend class RedeemCommand;

	void viewAllAccounts() const { // For testing
		for (int i = 0; i < accounts.getSize(); i++)
		{
			accounts[i].getHolder()->whoami();
			std::cout << "Bank: "<< name << std::endl;
			std::cout << "Acccount ID: " << accounts[i].getID() << std::endl;
			std::cout << std::endl;
		}
	}

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

	const Account& getAccount(int ID) const {
		for (int i = 0; i < accounts.getSize(); i++)
		{
			if (accounts[i].getID() == ID) {
				return accounts[i];
			}
		}

		throw std::logic_error("Account doesn't exist");
	}

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
	Collection<Employee> employees;
	Collection<Account> accounts;

	//void addEmployee(const Employee& eRef);
};