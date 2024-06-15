#pragma once
#include "User.h"
#include "Task.h"
#include "Bank.h"
#include "HeterogeneousContainer.hpp"
#include "Collection.h"
#include "MyString.h"

class System {
public:
	System& getInstance() {
		static System system;
		return system;
	}

private:
	System() = default;

	HeterogeneousContainer<User> users;
	Collection<Bank> banks;

	User* currentUser = nullptr; // Managed by users
};