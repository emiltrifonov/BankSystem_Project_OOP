#include "Command.h"

void Command::invalidCmd() const
{
	throw std::logic_error("Invalid command");
}
