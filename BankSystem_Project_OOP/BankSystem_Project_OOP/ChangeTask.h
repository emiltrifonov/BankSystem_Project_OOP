#pragma once
#include "Task.h"
#include "Client.h"
#include "Bank.h"
#include "MyString.h"

class ChangeTask : public Task {
public:
	ChangeTask(Client* cPtr, Bank* oldBankPtr, Bank* newBankPtr, int oldAccID);

	void list() const override final;
	void view() const override final;
	void approve() override final;
	void disapprove(const MyString& reason) override final;

	void validate() const;

	Task* clone() const override final;

private:
	Client* cPtr;
	Bank* oldBankPtr;
	Bank* newBankPtr;
	int oldAccID;

	mutable bool canApprove = false;
};