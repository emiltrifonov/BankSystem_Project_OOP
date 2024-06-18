#pragma once
#include "System.h"
#include "SystemCommand.h"
#include "Mystring.h"

class LoginCommand : public SystemCommand { // To do after User factory is created
public:
	LoginCommand(const MyString& egn, const MyString& password);

	void execute() override final;

private:
	User* user = nullptr;
	const MyString& password;

};