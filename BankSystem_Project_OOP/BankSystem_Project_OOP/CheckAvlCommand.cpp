#include <iostream>
#include <exception>
#include "System.h"
#include "CheckAvlCommand.h"

CheckAvlCommand::CheckAvlCommand(System* sPtr, const MyString& bankName, int accID) : ClientCommand(sPtr)
{
	int banksCount = sPtr->banks.getSize();
	Bank* bank = nullptr;

	for (int i = 0; i < banksCount; i++)
	{
		bank = &sPtr->banks[i];
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
