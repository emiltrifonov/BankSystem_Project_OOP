#include <iostream>
#include <exception>
#include "CreateBankCommand.h"
#include "System.h"
#include "SystemCommand.h"

CreateBankCommand::CreateBankCommand(System* sPtr, const MyString& bankName) : bankName(bankName)
{
	this->sPtr = sPtr;

	int banksCount = sPtr->banks.getSize();

	for (int i = 0; i < banksCount; i++)
	{
		if (sPtr->getBank(bankName)) {
			throw std::logic_error("Bank already exists");
		}
	}
}

void CreateBankCommand::execute()
{
	sPtr->banks.add(bankName);
	std::cout << "Bank created successfully" << std::endl;
}
