#include <iostream>
#include <exception>
#include <sstream>
#include "LoginCommand.h"
#include "MyString.h"
#include "System.h"
#include "ThirdPartyEmployee.h"

LoginCommand::LoginCommand(System* sPtr)
{
	this->sPtr = sPtr;

	if (sPtr->currentUser) {
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

	int usersCount = sPtr->users.getSize();
	User* currentUser = nullptr;

	for (int i = 0; i < usersCount; i++)
	{
		currentUser = sPtr->users[i].get();
		if (currentUser->getEGN() == egn && currentUser->getPassword() == password) {
			
			if (currentUser->isClient()) {
				sPtr->currentUser = (Client*)currentUser;
			}
			else if (currentUser->isEmployee()) {
				sPtr->currentUser = (Employee*)currentUser;
			}
			else if (currentUser->isThirdPartyEmployee()) {
				sPtr->currentUser = (ThirdPartyEmployee*)currentUser;
			}

			std::cout << "Successful login, welcome "
				<< currentUser->getFirstName() << " " << currentUser->getLastName() << "!" << std::endl;
			
			/*if (currentUser->isEmployee())
			{
				((Employee*)currentUser)->whoami();
			}*/

			return;
		}
	}

	invalidCmd();
}
