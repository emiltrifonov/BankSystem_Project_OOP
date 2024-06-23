#include <iostream>
#include <exception>
#include "System.h"
#include "CheckAvlCommand.h"

CheckAvlCommand::CheckAvlCommand(const MyString& bankName, int accID)
{
	int banksCount = System::getInstance().getBanksCount();
	Bank* bank = nullptr;

	for (int i = 0; i < banksCount; i++)
	{
		bank = System::getInstance().getBankAt(i);
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
