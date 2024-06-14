#pragma once
#include <stdio.h>
#include "Client.h"

class Account {
public:
	Account() = default;
	Account(const Client* ptr, int id);
	void addBalance(double toAdd);

	int getID() const;
	double getBalance() const;
	const Client* getHolder() const;

private:
	const Client* holder = nullptr;
	double balance = 0;
	int id = 0;
};