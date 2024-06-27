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
	void viewAccount(int ID) const;
	Account& getAccountAt(int index);
	Account& getAccount(int ID);

	bool existsAccount(int accID) const;

	void addEmployee(Employee* ePtr);

private:
	const MyString name;
	// Does not manage memory! (System manages all the users, here we only keep pointers to the bank's employees)
	MyVector<Employee*> employees;
	Collection<Account> accounts;
};