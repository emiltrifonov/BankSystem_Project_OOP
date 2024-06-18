#include <iostream>
#include <exception>
#include "System.h"

System& System::getInstance() {
	static System system;
	return system;
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

User* System::getUser(const MyString& egn)
{
	for (int i = 0; i < users.getSize(); i++)
	{
		if (users[i]->getEGN() == egn) {
			return users[i];
		}
	}

	return nullptr;
}
