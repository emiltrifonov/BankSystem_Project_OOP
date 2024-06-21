#include <iostream>
#include <exception>
#include <sstream>
#include "LoginCommand.h"
#include "MyString.h"
#include "System.h"

LoginCommand::LoginCommand()
{
	if (System::getInstance().currentUser) {
		invalidCmd();
	}
}

void LoginCommand::execute()
{
	MyString egn, password;

	{
		std::cout << "EGN: ";
		char buffer[1024];
		std::cin.getline(buffer, 1024);
		std::stringstream ss(buffer);
		ss >> egn;
		if (!ss.eof()) {
			invalidCmd();
		}
	}
	

	{
		std::cout << "Password: ";
		char buffer[1024];
		std::cin.getline(buffer, 1024);
		std::stringstream ss(buffer);
		ss >> password;
		if (!ss.eof()) {
			invalidCmd();
		}
	}

	int usersCount = System::getInstance().users.getSize();
	User* currentUser = nullptr;

	for (int i = 0; i < usersCount; i++)
	{
		currentUser = System::getInstance().users[i];
		if (currentUser->getEGN() == egn && currentUser->getPassword() == password) {
			System::getInstance().currentUser = currentUser;
			std::cout << "Successful login, welcome "
				<< currentUser->getFirstName() << " " << currentUser->getLastName() << "!" << std::endl;
			return;
		}
	}

	invalidCmd();
}
