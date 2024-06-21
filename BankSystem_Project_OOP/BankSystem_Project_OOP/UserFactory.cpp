#include <iostream>
#include <exception>
#include <limits>
#include "UserFactory.h"
#include "User.h"
#include "Bank.h"
#include "Client.h"
#include "Employee.h"
#include "ThirdPartyEmployee.h"
#include "System.h"
#include "MyString.h"
#include "EGN.h"

static MyString firstName;
static MyString lastName;
static MyString egn;
static int age;
static int role;
static MyString password;

static bool isLatinLetter(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

static void validateString(const MyString& str) {
    if (str.isEmpty()) {
        throw std::logic_error("Empty string not allowed");
    }
}

static void validateName(const MyString& name) {
    validateString(name);

    for (size_t i = 0; i < name.getLength(); i++)
    {
        if (!isLatinLetter(name[i])) {
            throw std::logic_error("Invalid name");
        }
    }
}

static void resetCin() {
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

static void validateAge() {
    if (age < 18) {
        resetCin();
        throw std::logic_error("Age must be at least 18");
    }
}

static void validateRole() {
    if (role < 1 || role > 3) {
        resetCin();
        throw std::logic_error("Role must be 1,2 or 3");
    }
}

static void validateEgn() {
    User* u = System::getInstance().getUser(egn);

    if (u) {
        throw std::logic_error("User with this EGN already exists");
    }
}

static void validateBank(const Bank* bPtr) {
    if (!bPtr) {
        throw std::logic_error("Bank doesn't exist");
    }
}

static void getName() {
    std::cout << "First name: ";
    std::cin >> firstName;
    validateName(firstName);

    std::cout << "Last name: ";
    std::cin >> lastName;
    validateName(lastName);
}

static void getEgn() {
    std::cout << "EGN: ";
    std::cin >> egn;

    validateEgn();
}

static void getAge() {
    std::cout << "Age: ";
    std::cin >> age;

    validateAge();
}

static void getRole() {
    std::cout << "Role (Client(1) / Employee(2) / ThirdPartyEmployee(3)) : ";
    std::cin >> role;

    validateRole();
}

static void getPassword() {
    std::cout << "Password: ";
    std::cin >> password;
    validateString(password);
}

static User* handleClient() {
    std::cout << "Address: ";
    MyString address;
    std::cin >> address;
    validateString(address);

    return new Client(firstName, lastName, egn, password, age, address);
}

static User* handleEmployee() {
    std::cout << "Bank associated: ";
    MyString bankName;
    std::cin >> bankName;

    Bank* b = System::getInstance().getBank(bankName);
    validateBank(b);

    Employee* e = new Employee(firstName, lastName, egn, password, age);
    b->addEmployee(*e);

    return e;
}

static User* handleThirdPartyEmployee() {
    return new ThirdPartyEmployee(firstName, lastName, egn, password, age);
}

User* userFactory()
{
    getName();
    getEgn();
    getAge();
    getRole();
    getPassword();

    switch (role)
    {
    // Client
    case 1: return handleClient();
    // Employee
    case 2: return handleEmployee();
    // ThirdPartyEmployee
    case 3: return handleThirdPartyEmployee();
    }

    return nullptr;
}
