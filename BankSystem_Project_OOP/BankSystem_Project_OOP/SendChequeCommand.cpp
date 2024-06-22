#include <iostream>
#include <exception>
#include "System.h"
#include "Command.h"
#include "Client.h"
#include "SendChequeCommand.h"

SendChequeCommand::SendChequeCommand(System* sPtr, double sum, const MyString& verificationCode, const MyString& recipientEGN)
	: UserCommand(sPtr), sum(sum), code(verificationCode), recipientEGN(recipientEGN), sender(sPtr->currentUser)
{
	this->sPtr = sPtr;

	if (!isCurrentUserThirdPartyEmployee() || sum <= 0) {
		invalidCmd();
	}

	int usersCount = sPtr->users.getSize();
	User* current = nullptr;

	for (int i = 0; i < usersCount; i++)
	{
		 current = sPtr->users[i].get();

		if (current->getEGN() == recipientEGN) {
			if (current->isClient()) {
				recipient = static_cast<Client*>(current);
				return;
			}

			throw std::logic_error("Recipient doesn't exist");
		}
	}

	throw std::logic_error("Recipient doesn't exist");
}

void SendChequeCommand::execute()
{
	recipient->addCheque(new Cheque(code, sum));
	MyString message = "You have a cheque assigned to you by ";
	message += sender->getFirstName();
	message += " ";
	message += sender->getLastName();
	message += "(verification code: ";
	message += code.getCode();
	message += ")";
	recipient->addMessage(message);
}

bool SendChequeCommand::isCurrentUserThirdPartyEmployee() const
{
	return sPtr->currentUser->isThirdPartyEmployee();
}
