#pragma once
#include "System.h"
#include "ClientCommand.h"
#include "Bank.h"

class CloseCommand : public ClientCommand {
public:
	CloseCommand(System* sPtr, const MyString& bankName, int accID);

	void execute() override final;

private:
	Bank* bankPtr = nullptr;
	int accID = -1;
};