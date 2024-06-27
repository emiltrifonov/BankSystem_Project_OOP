#include <iostream>
#include <exception>
#include <sstream>
#include "LoginCommand.h"
#include "MyString.h"
#include "System.h"
#include "ThirdPartyEmployee.h"

LoginCommand::LoginCommand()
{
	if (System::getInstance().isUserLogged()) {
		invalidCmd();
	}
}

void LoginCommand::execute()
{
	MyString egn, password;
	read(egn, "EGN: ");
	read(password, "Password: ");

	int usersCount = System::getInstance().getUsersCount();
	User* currentUser = nullptr;

	for (int i = 0; i < usersCount; i++)
	{
		currentUser = System::getInstance().getUserAt(i);
		if (currentUser->getEGN() == egn && currentUser->getPassword() == password) {
			System::getInstance().login(currentUser);

			std::cout << "Successful login, welcome "
				<< currentUser->getFirstName() << " " << currentUser->getLastName() << "!" << std::endl;

			return;
		}
	}

	invalidCmd();
}

void LoginCommand::read(MyString& toRead, MyString prompt) const
{
	std::cout << prompt;

	char buffer[1024];
	std::cin.getline(buffer, 1024);

	std::stringstream ss(buffer);
	ss >> toRead;

	if (!ss.eof()) {
		invalidCmd();
	}
}
