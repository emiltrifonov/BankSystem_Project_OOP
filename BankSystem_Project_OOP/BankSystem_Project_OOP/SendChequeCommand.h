#pragma once
#include "System.h"
#include "Command.h"
#include "EGN.h"
#include "Client.h"

class SendChequeCommand : public Command {
public:
	SendChequeCommand(double sum, const MyString& verificationCode, const MyString& recipientEGN);

	void execute() override final;

private:
	double sum = -1;
	VerificationCode code;
	EGN recipientEGN;
	Client* recipient = nullptr;

	bool isCurrentUserThirdPartyEmployee() const;
};