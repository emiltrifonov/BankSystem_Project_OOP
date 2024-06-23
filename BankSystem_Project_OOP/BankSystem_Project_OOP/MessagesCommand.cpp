#include <iostream>
#include <exception>
#include "MessagesCommand.h"

void MessagesCommand::execute()
{
	const Client* user = dynamic_cast<Client*>(System::getInstance().getCurrentUser());
	int count = user->getMessagesCount();

	for (int i = 0; i < count; i++)
	{
		std::cout << "[" << (i + 1) << "] - " << user->getMessageAt(i) << std::endl;
	}
}
