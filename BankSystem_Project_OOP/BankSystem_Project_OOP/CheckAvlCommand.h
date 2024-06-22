#pragma once
#include "System.h"
#include "Bank.h"
#include "ClientCommand.h"

class CheckAvlCommand : public ClientCommand {
public:
	CheckAvlCommand(System* sPtr, const MyString& bankName, int accID);

	void execute() override final;

private:
	double balance = -1;
};