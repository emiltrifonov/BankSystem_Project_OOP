#include <iostream>
#include <exception>
#include "System.h"

System& System::getInstance() {
	static System system;
	return system;
}

User* System::getCurrentUser()
{
	return currentUser;
}

void System::logout()
{
	currentUser = nullptr;
}

void System::exitSystem()
{
	isRunning = false;
}

void System::login(User* user)
{
	currentUser = user;
}

bool System::isUserLogged() const
{
	return currentUser;
}

User* System::getUserAt(int index)
{
	return users[index].get();
}

Bank* System::getBankAt(int index)
{
	return &banks[index];
}

int System::getUsersCount() const
{
	return users.getSize();
}

int System::getBanksCount() const
{
	return banks.getSize();
}

void System::addBank(const MyString& bankName)
{
	banks.add(bankName);
}

void System::addUser(User* user)
{
	users.push(user);
}

bool System::getIsRunning() const
{
	return isRunning;
}

Bank* System::getBank(const MyString& name)
{
	for (int i = 0; i < banks.getSize(); i++)
	{
		if (banks[i].getName() == name) {
			return &banks[i];
		}
	}

	return nullptr;
}

User* System::getUser(const EGN& egn)
{
	for (int i = 0; i < users.getSize(); i++)
	{
		if (users[i]->getEGN() == egn) {
			return users[i].get();
		}
	}

	return nullptr;
}
