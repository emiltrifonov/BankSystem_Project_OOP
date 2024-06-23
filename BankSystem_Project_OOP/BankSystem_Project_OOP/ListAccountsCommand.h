#pragma once
#include "System.h"
#include "ClientCommand.h"

class ListAccountsCommand : public ClientCommand{
public:
	ListAccountsCommand(const MyString& bankName);

	void execute() override final;

private:
	Bank* bPtr = nullptr;
};