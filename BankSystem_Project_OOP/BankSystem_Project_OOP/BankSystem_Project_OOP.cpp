#include <iostream>
#include <exception>
#include <limits>
#include "System.h"
#include "Command.h"
#include "CommandFactory.h"

#include "OpenTask.h"

static void resetCin() {
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

const static void run() {
	System s;

	while (true)
	{
		try 
		{
			Command* cmd = CommandFactory(&s);
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