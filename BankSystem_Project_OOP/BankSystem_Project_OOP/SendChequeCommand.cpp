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
	Cheque* c = new Cheque(code, sum);
	std::cout << c->getCode() << " " << c->getSum() << std::endl;
	recipient->addCheque(new Cheque(code, sum));
	MyString message = "You have a cheque assigned to you by ";
	message += sender->getFirstName();
	message += " ";
	message += sender->getLastName();
	message += " (verification code: ";
	message += code.getCode();
	message += ").";
	recipient->addMessage({ message, nullptr });

	std::cout << "Cheque sent." << std::endl;
}

bool SendChequeCommand::isCurrentUserThirdPartyEmployee() const
{
	return System::getInstance().getCurrentUser()->isThirdPartyEmployee();
}
