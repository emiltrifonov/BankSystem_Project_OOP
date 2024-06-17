#include <iostream>
#include <exception>
#include "MessagesCommand.h"

void MessagesCommand::execute()
{
	const Client* user = static_cast<Client*>(System::getInstance().currentUser);
	int count = user->messages.getSize();

	for (int i = 0; i < count; i++)
	{
		std::cout << "[" << (i + 1) << "] - " << user->messages[i] << std::endl;
	}
}
