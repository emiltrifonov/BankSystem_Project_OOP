#pragma once
#include "ClientCommand.h"
#include "System.h"

class ChangeCommand : public ClientCommand {
public:
	ChangeCommand(System* sPtr, const MyString& oldBankName, const MyString& newBankName, int oldAccID);

	void execute() override final;

private:
	Bank* currenBankPtr = nullptr;
	Bank* newBankPtr = nullptr;
	int accID;

};