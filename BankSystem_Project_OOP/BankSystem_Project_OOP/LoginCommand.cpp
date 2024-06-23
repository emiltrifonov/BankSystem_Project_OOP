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

	std::cout << "EGN: ";
	char buffer1[1024];
	std::cin.getline(buffer1, 1024);
	std::stringstream ss1(buffer1);
	ss1 >> egn;
	if (!ss1.eof()) {
		invalidCmd();
	}
	
	std::cout << "Password: ";
	char buffer2[1024];
	std::cin.getline(buffer2, 1024);
	std::stringstream ss2(buffer2);
	ss2 >> password;
	if (!ss2.eof()) {
		invalidCmd();
	}

	int usersCount = System::getInstance().getUsersCount();
	User* currentUser = nullptr;

	for (int i = 0; i < usersCount; i++)
	{
		currentUser = System::getInstance().getUserAt(i);
		if (currentUser->getEGN() == egn && currentUser->getPassword() == password) {
			
			// Tova dano da ne e bilo vajno
			/*if (currentUser->isClient()) {
				System::getInstance().currentUser = (Client*)currentUser;
			}
			else if (currentUser->isEmployee()) {
				System::getInstance().currentUser = (Employee*)currentUser;
			}
			else if (currentUser->isThirdPartyEmployee()) {
				System::getInstance().currentUser = (ThirdPartyEmployee*)currentUser;
			}*/

			System::getInstance().login(currentUser);

			std::cout << "Successful login, welcome "
				<< currentUser->getFirstName() << " " << currentUser->getLastName() << "!" << std::endl;

			return;
		}
	}

	invalidCmd();
}
