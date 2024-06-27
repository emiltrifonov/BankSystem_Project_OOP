#include <iostream>
#include <exception>
#include "System.h"
#include "Command.h"
#include "Client.h"
#include "SendChequeCommand.h"

SendChequeCommand::SendChequeCommand(double sum, const MyString& verificationCode, const MyString& recipientEGN)
	: sum(sum), code(verificationCode), recipientEGN(recipientEGN), sender(System::getInstance().getCurrentUser())
{
	if (!isCurrentUserThirdPartyEmployee() || sum <= 0) {
		invalidCmd();
	}
	
	int usersCount = System::getInstance().getUsersCount();
	User* current = nullptr;

	for (int i = 0; i < usersCount; i++)
	{
		 current = System::getInstance().getUserAt(i);

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
	recipient->addCheque(Cheque(code, sum));

	Message message = generateMessage();

	recipient->addMessage(message);

	std::cout << "Cheque sent." << std::endl;
}

Message SendChequeCommand::generateMessage() const
{
	MyString message = "You have a cheque assigned to you by ";
	message += sender->getFirstName();
	message += " ";
	message += sender->getLastName();
	message += " (verification code: ";
	message += code.getCode();
	message += ").";

	return Message(message,nullptr);
}

bool SendChequeCommand::isCurrentUserThirdPartyEmployee() const
{
	return System::getInstance().getCurrentUser()->isThirdPartyEmployee();
}
