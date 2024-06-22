#pragma once
#include "System.h"
#include "ClientCommand.h"
#include "Bank.h"

class OpenCommand : public ClientCommand {
public:
	OpenCommand(System* sPtr, const MyString& bankName);

	void execute() override final;

private:
	Bank* bankPtr = nullptr;
};