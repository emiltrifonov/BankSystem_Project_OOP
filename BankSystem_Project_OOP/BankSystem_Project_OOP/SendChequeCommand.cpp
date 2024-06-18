#include <iostream>
#include <exception>
#include "System.h"
#include "Command.h"
#include "Client.h"
#include "SendChequeCommand.h"

SendChequeCommand::SendChequeCommand(double sum, const MyString& verificationCode, const MyString& recipientEGN)
	: code(verificationCode), recipientEGN(recipientEGN)
{
	if (!isCurrentUserThirdPartyEmployee() || sum <= 0) {
		invalidCmd();
	}

	int usersCount = System::getInstance().users.getSize();
	User* current = nullptr;

	for (int i = 0; i < usersCount; i++)
	{
		 current = System::getInstance().users[i];

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
}

bool SendChequeCommand::isCurrentUserThirdPartyEmployee() const
{
	return System::getInstance().currentUser->isThirdPartyEmployee();
}
