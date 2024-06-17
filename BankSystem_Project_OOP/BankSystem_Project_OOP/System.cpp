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

bool System::existsUser(const MyString& egn) const
{
	for (int i = 0; i < users.getSize(); i++)
	{
		if (users[i]->getEGN() == egn) {
			return true;
		}
	}

	return false;
}

bool System::existsBank(const MyString& name) const
{
	for (int i = 0; i < banks.getSize(); i++)
	{
		if (banks[i].getName() == name) {
			return true;
		}
	}

	return false;
}
