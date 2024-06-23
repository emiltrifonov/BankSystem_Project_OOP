#pragma once
#include "Task.h"
#include "Bank.h"
#include "PolymorphicPtr.hpp"
#include "MyString.h"
#include "Employee.h"
#include "ThirdPartyEmployee.h"

// Singleton
class System {
public:
	static System& getInstance();

	System(const System& other) = delete;
	System& operator=(const System& other) = delete;

	User* getCurrentUser();
	bool getIsRunning() const;

	void logout();
	void exitSystem();
	void login(User* user);
	bool isUserLogged() const;

	User* getUserAt(int index);
	Bank* getBankAt(int index);

	int getUsersCount() const;
	int getBanksCount() const;
	void addBank(const MyString& bankName);
	void addUser(User* user);

	Bank* getBank(const MyString& name);
	User* getUser(const EGN& egn);

private:
	MyVector<PolymorphicPtr<User>> users;

	Collection<Bank> banks;

	User* currentUser = nullptr; // Managed by Container of users

	bool isRunning = true;

	System() = default;
};