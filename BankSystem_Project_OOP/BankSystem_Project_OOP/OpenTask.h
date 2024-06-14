#pragma once
#include "Task.h"
#include "Client.h"
#include "Bank.h"
#include "MyString.h"

class OpenTask : public Task {
public:
	OpenTask(Client* cPtr, Bank* bPtr);

	void list() const override final;
	void view() const override final;
	void approve() override final;
	void disapprove(const MyString& reason) override final;

	Task* clone() const override final;

private:
	Client* cPtr;
	Bank* bPtr;
};