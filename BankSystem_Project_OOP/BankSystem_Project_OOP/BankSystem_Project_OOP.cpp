#include <iostream>
#include <exception>
#include <limits>
#include "Command.h"
#include "CommandFactory.h"

static void resetCin() {
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

const static void run() {
	while (true)
	{
		try 
		{
			Command* cmd = CommandFactory();
			cmd->execute();
			delete cmd;
			resetCin();
		}
		catch (std::exception& e)
		{
			if (strcmp(e.what(),"")) {
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