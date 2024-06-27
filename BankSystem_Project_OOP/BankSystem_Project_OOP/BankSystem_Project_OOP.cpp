#include <iostream>
#include <exception>
#include <limits>
#include "System.h"
#include "Command.h"
#include "CommandFactory.h"
#include "Utility.h"

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

static void run() {
	while (System::getInstance().getIsRunning())
	{
		try 
		{
			Command* cmd = CommandFactory();
			try 
			{
				cmd->execute();
			}
			catch (std::exception& e) {
				delete cmd;
				resetCin();
				std::cout << std::endl;
				throw e;
			}
			delete cmd;
			resetCin();
			std::cout << std::endl;
		}
		catch (std::exception& e)
		{
			if (strcmp(e.what(),"") != 0) { // for console formatting
				std::cout << e.what() << std::endl << std::endl;
			}
			resetCin();
		}
	}
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //first line in main function
	run();
}