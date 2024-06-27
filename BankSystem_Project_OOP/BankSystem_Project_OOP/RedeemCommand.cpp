#include <iostream>
#include <exception>
#include "System.h"
#include "RedeemCommand.h"
#include "MyString.h"

RedeemCommand::RedeemCommand(const MyString& bankName, int accID, const MyString& verificationCode)
{
	Bank* bank = System::getInstance().getBank(bankName);
	if (!bank) {
		invalidCmd();
	}

	cheque = getCheque(verificationCode);
	account = &bank->getAccount(accID);
}

void RedeemCommand::execute()
{
	Client* client = (Client*)(System::getInstance().getCurrentUser());
	client->getRedeemedCheques().add(*cheque);
	account->addBalance(cheque->getSum());

	std::cout << cheque->getSum() << "$ added to *" << account->getID() << "." << std::endl;

	client->getPendingCheques().removeAt(chequeIndex);
}

Cheque* RedeemCommand::getCheque(const MyString& verificationCode)
{
	Client* current = (Client*)(System::getInstance().getCurrentUser());
	int count = current->getPendingCheques().getSize();
	Cheque* currCh = nullptr;

	for (int i = 0; i < count; i++)
	{
		currCh = &current->getPendingCheques()[i];
		if (currCh->getCode() == verificationCode) {
			chequeIndex = i;
			return currCh;
		}
	}

	invalidCmd();
}
