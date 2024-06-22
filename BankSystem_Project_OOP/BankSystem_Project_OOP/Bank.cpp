#include <iostream>
#include "Bank.h"
#include "System.h"

Bank::Bank(const MyString& name) : name(name) { }

const MyString& Bank::getName() const
{
	return name;
}

Employee* Bank::getLeastBusyEmployee(MyVector<PolymorphicPtr<User>>& users)
{
	//int currInd = -1;
	int minTasks = INT_MAX;
	Employee* result = nullptr;
	for (int i = 0; i < users.getSize(); i++)
	{
		User* currentUser = users[i].get();
		if (users[i].get()->isEmployee() || (Employee*)users[i].get().
		{
			Employee* currentEmployee = (Employee*)currentUser;
			if (currentEmployee->getTaskCount() < minTasks) {
				//currInd = i;
				result = currentEmployee;
				minTasks = currentEmployee->getTaskCount();
			}
		}
	}

	//return &employees[currInd];
	return result;
}

const static unsigned getID() {
	static unsigned ID = 100;
	return ID++;
}

void Bank::openAccount(const Client* cPtr)
{
	accounts.add(*new Account(cPtr, getID()));
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

//void Bank::addEmployee(const Employee& eRef)
//{
//	employees.add(eRef);
//}