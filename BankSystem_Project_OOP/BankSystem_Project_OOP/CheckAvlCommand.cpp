#include <iostream>
#include <exception>
#include "CheckAvlCommand.h"

CheckAvlCommand::CheckAvlCommand(const MyString& bankName, int accID)
{
	int banksCount = System::getInstance().banks.getSize();
	Bank* bank = nullptr;

	for (int i = 0; i < banksCount; i++)
	{
		bank = &System::getInstance().banks[i];
		if (bank->getName() == bankName) {
			break;
		}
	}

	if (bank) {
		balance = bank->getAccount(accID).getBalance();
	}
	else {
		invalidCmd();
	}
}

void CheckAvlCommand::execute()
{
	std::cout << balance << "$" << std::endl;
}
