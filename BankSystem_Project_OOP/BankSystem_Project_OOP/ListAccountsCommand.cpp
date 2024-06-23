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
	const EGN egn = System::getInstance().getCurrentUser()->getEGN();
	const Account* accPtr = nullptr;

	for (int i = 0; i < bPtr->getAccountsCount(); i++)
	{
		accPtr = &bPtr->getAccountAt(i);
		if (accPtr->getHolder()->getEGN() == egn) {
			std::cout << "* " << accPtr->getID() << std::endl;
		}
	}
}
