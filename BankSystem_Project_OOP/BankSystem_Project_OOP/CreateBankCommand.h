#pragma once
#include "System.h"
#include "SystemCommand.h"

class CreateBankCommand : public SystemCommand {
public:
	CreateBankCommand(const MyString& bankName);

	void execute() override final;

private:
	const MyString bankName;

};