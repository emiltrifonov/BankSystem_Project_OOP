#include <iostream>
#include <exception>
#include "System.h"
#include "RedeemCommand.h"
#include "MyString.h"

RedeemCommand::RedeemCommand(System* sPtr, const MyString& bankName, int accID, const MyString& verificationCode)
	: ClientCommand(sPtr)
{
	Bank* bank = sPtr->getBank(bankName);
	if (!bank) {
		invalidCmd();
	}

	cheque = getCheque(verificationCode);
	account = &bank->getAccount(accID);
}

void RedeemCommand::execute()
{
	Client* client = static_cast<Client*>(sPtr->currentUser);

	client->pendingCheques.removeAt(chequeIndex);
	client->redeemedCheques.add(*cheque);

	//std::cout << "Sum to redeem: " << cheque->getSum() << std::endl;

	account->addBalance(cheque->getSum());

	std::cout << cheque->getSum() << "$ added to *" << account->getID() << "." << std::endl;
}

Cheque* RedeemCommand::getCheque(const MyString& verificationCode)
{
	int count = static_cast<Client*>(sPtr->currentUser)->pendingCheques.getSize();
	Client* current = static_cast<Client*>(sPtr->currentUser);
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
