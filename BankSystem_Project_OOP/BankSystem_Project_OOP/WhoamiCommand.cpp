#include <iostream>
#include <exception>
#include "WhoamiCommand.h"
#include "System.h"

void WhoamiCommand::execute()
{
	System::getInstance().getCurrentUser()->whoami();
}
