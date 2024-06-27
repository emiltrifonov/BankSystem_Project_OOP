#pragma once
#include "System.h"
#include "Cheque.h"
#include "Account.h"
#include "ClientCommand.h"
#include "MyString.h"

class RedeemCommand : public ClientCommand {
public:
	RedeemCommand(const MyString& bankName, int accID, const MyString& verificationCode);

	void execute() override final;

private:
	Cheque* cheque = nullptr;
	int chequeIndex = -1;
	Account* account = nullptr;

	Cheque* getCheque(const MyString& verificationCode);
};