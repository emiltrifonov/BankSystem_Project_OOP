#include <iostream>
#include <exception>
#include "CreateBankCommand.h"
#include "System.h"
#include "SystemCommand.h"

CreateBankCommand::CreateBankCommand(const MyString& bankName) : bankName(bankName)
{
	int banksCount = System::getInstance().banks.getSize();

	for (int i = 0; i < banksCount; i++)
	{
		if (System::getInstance().getBank(bankName)) {
			throw std::logic_error("Bank already exists");
		}
	}
}

void CreateBankCommand::execute()
{
	System::getInstance().banks.add(bankName);
}
