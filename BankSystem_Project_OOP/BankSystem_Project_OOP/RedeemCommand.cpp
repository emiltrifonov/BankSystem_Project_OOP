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
	Client* client = static_cast<Client*>(System::getInstance().currentUser);

	client->pendingCheques.removeAt(chequeIndex);
	client->redeemedCheques.add(*cheque);

	account->addBalance(cheque->getSum());
}

Cheque* RedeemCommand::getCheque(const MyString& verificationCode)
{
	int count = static_cast<Client*>(System::getInstance().currentUser)->pendingCheques.getSize();
	Client* current = static_cast<Client*>(System::getInstance().currentUser);
	Cheque* currCh = nullptr;

	for (int i = 0; i < count; i++)
	{
		currCh = &current->pendingCheques[i];
		if (currCh->getCode() == verificationCode) {
			chequeIndex = i;
			return currCh;
		}
	}

	invalidCmd();
}
