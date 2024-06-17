#include <iostream>
#include <exception>
#include "ListAccountsCommand.h"
#include "System.h"
#include "MyString.h"
#include "EGN.h"
#include "Account.h"

ListAccountsCommand::ListAccountsCommand(const MyString& bankName)
{
	bPtr = System::getInstance().getBank(bankName);

	if (!bPtr) {
		invalidCmd();
	}
}

void ListAccountsCommand::execute()
{
	const EGN egn = System::getInstance().currentUser->getEGN();
	const Account* accPtr;

	for (int i = 0; i < bPtr->accounts.getSize(); i++)
	{
		accPtr = &bPtr->accounts[i];
		if (bPtr->accounts[i].getHolder()->getEGN() == egn) {
			std::cout << "* " << accPtr->getID() << std::endl;
		}
	}
}
