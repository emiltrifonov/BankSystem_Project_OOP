#pragma once
#include "User.h"
#include "Task.h"
#include "Bank.h"
#include "HeterogeneousContainer.hpp"
#include "Collection.hpp"
#include "MyString.h"

// Singleton
class System {
public:
	static System& getInstance();

	// System commands
	friend class ExitCommand;
	friend class CreateBankCommand;

	// Third-Party employee commands
	friend class SendChequeCommand;

	// Employee commands
	friend class EmployeeCommand;
	friend class ListTasksCommand;
	friend class ViewTaskCommand;
	friend class ApproveCommand;
	friend class DisapproveCommand;
	friend class ValidateCommand;

	// Client commands
	friend class ClientCommand;
	friend class CheckAvlCommand;
	friend class OpenCommand;
	friend class CloseCommand;
	friend class ChangeCommand;
	friend class RedeemCommand;
	friend class ListAccountsCommand;
	friend class MessagesCommand;

	const void printBanks() const {
		for (int i = 0; i < banks.getSize(); i++)
		{
			std::cout << banks[i].getName() << std::endl;
		}
	}

	const void printUsers() const {
		for (int i = 0; i < users.getSize(); i++)
		{
			users[i]->whoami();
		}
	}

private:
	HeterogeneousContainer<User> users;
	Collection<Bank> banks;

	User* currentUser = nullptr; // Managed by Container of users

	System() = default;

	Bank* getBank(const MyString& name);

	bool existsUser(const MyString& egn) const;
	bool existsBank(const MyString& name) const;
};