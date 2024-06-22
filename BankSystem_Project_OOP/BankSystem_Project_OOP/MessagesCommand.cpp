#include <iostream>
#include <exception>
#include "MessagesCommand.h"

MessagesCommand::MessagesCommand(System* sPtr) : ClientCommand(sPtr) { }

void MessagesCommand::execute()
{
	const Client* user = dynamic_cast<Client*>(sPtr->currentUser);
	int count = user->messages.getSize();

	for (int i = 0; i < count; i++)
	{
		std::cout << "[" << (i + 1) << "] - " << user->messages[i] << std::endl;
	}
}
