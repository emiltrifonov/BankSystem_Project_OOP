#include <iostream>
#include <exception>
#include "LoginCommand.h"
#include "MyString.h"

LoginCommand::LoginCommand(const MyString& egn, const MyString& password) : password(password)
{
	user = System::getInstance().getUser(egn);

	if (!user) {
		invalidCmd();
	}
}

void LoginCommand::execute()
{
	System::getInstance().currentUser = user;
}
