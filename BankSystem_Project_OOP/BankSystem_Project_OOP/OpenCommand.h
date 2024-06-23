#pragma once
#include "System.h"
#include "ClientCommand.h"
#include "Bank.h"

class OpenCommand : public ClientCommand {
public:
	OpenCommand(const MyString& bankName);

	void execute() override final;

private:
	Bank* bankPtr = nullptr;
};