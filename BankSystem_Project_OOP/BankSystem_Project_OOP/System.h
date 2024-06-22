#pragma once
#include "Task.h"
#include "Bank.h"
#include "UserContainer.hpp"
#include "PolymorphicPtr.hpp"
#include "MyString.h"
#include "Employee.h"

// Singleton
class System {
public:
	//static System& getInstance();

	System() = default;

	System(const System& other) = delete;
	System& operator=(const System& other) = delete;

	// System commands
	friend class ExitCommand;
	friend class CreateBankCommand;
	friend class LoginCommand;
	friend class SignupCommand;

	// User commands
	friend class UserCommand;
	friend class HelpCommand;

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

	friend class Bank;

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

	Bank* getBank(const MyString& name);
	User* getUser(const EGN& egn);

private:
	//UserContainer users;
	MyVector<PolymorphicPtr<User>> users;
	Collection<Bank> banks;

	User* currentUser = nullptr; // Managed by Container of users

	//System() = default;
};