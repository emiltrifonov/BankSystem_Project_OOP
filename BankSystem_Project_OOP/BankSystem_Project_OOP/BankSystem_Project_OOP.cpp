#include <iostream>
#include <exception>
#include <limits>
#include "System.h"
#include "Command.h"
#include "CommandFactory.h"
#include "Utility.h"

static void run() {
	while (System::getInstance().getIsRunning())
	{
		try 
		{
			Command* cmd = CommandFactory();
			cmd->execute();
			delete cmd;
			resetCin();
			std::cout << std::endl;
		}
		catch (std::exception& e)
		{
			if (strcmp(e.what(),"") != 0) {
				std::cout << e.what() << std::endl << std::endl;
			}
			resetCin();
		}
	}
}

int main()
{
	run();
}