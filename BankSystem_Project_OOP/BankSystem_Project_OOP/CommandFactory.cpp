#include <iostream>
#include <exception>
#include <sstream>
#include "CommandFactory.h"
#include "AllCommands.h"

System* s = nullptr;

// Utility
static void validateCommand(std::stringstream& ss) {
	if (!ss.eof()) {
		throw std::logic_error("Command message format not supported");
	}
}

static void validateString(const MyString& str) {
	if (str.isEmpty()) {
		throw std::logic_error("Empty string not allowed");
	}
}

static int readInteger(std::istream& is) {
	int result;

	is >> result;

	if (is.fail()) {
		throw std::logic_error("Invalid integer");
	}

	return result;
}

static double readDouble(std::istream& is) {
	double result;

	is >> result;

	if (is.fail()) {
		throw std::logic_error("Invalid double");
	}

	return result;
}

// System commands
static Command* handleExit(std::stringstream& ss) {
	validateCommand(ss);

	return new ExitCommand(s);
}

static Command* handleCreateBank(std::stringstream& ss) {
	MyString bankName;
	ss >> bankName;
	validateString(bankName);
	validateCommand(ss);

	return new CreateBankCommand(s, bankName);
}

static Command* handleLogin(std::stringstream& ss) {
	validateCommand(ss);

	return new LoginCommand(s);
}

static Command* handleSignup(std::stringstream& ss) {
	validateCommand(ss);

	return new SignupCommand(s);
}

// User commands
static Command* handleHelp(std::stringstream& ss) {
	validateCommand(ss);

	return new HelpCommand(s);
}

// Client commands
static Command* handleCheckAvl(std::stringstream& ss) {
	MyString bankName;
	ss >> bankName;

	int accID;
	accID = readInteger(ss);

	validateCommand(ss);

	return new CheckAvlCommand(s, bankName, accID);
}

static Command* handleOpen(std::stringstream& ss) {
	MyString bankName;
	ss >> bankName;

	validateCommand(ss);
	
	return new OpenCommand(s, bankName);
}

static Command* handleClose(std::stringstream& ss) {
	MyString bankName;
	ss >> bankName;
	int accID;
	accID = readInteger(ss);

	validateCommand(ss);

	return new CloseCommand(s, bankName, accID);
}

static Command* handleChange(std::stringstream& ss) {
	MyString newBankName;
	ss >> newBankName;
	MyString currentBankName;
	ss >> currentBankName;

	int accID;
	accID = readInteger(ss);

	validateCommand(ss);

	return new ChangeCommand(s, newBankName, currentBankName, accID);
}

static Command* handleRedeem(std::stringstream& ss) {
	MyString bankName;
	ss >> bankName;
	int accID;
	accID = readInteger(ss);
	MyString verificationCode;
	ss >> verificationCode;

	validateCommand(ss);

	return new RedeemCommand(s, bankName, accID, verificationCode);
}

static Command* handleList(std::stringstream& ss) {
	MyString bankName;
	ss >> bankName;

	validateCommand(ss);

	return new ListAccountsCommand(s, bankName);
}

static Command* handleMessages(std::stringstream& ss) {
	validateCommand(ss);

	return new MessagesCommand(s);
}

// Employee commands
static Command* handleTasks(std::stringstream& ss) {
	validateCommand(ss);

	return new ListTasksCommand(s);
}

static Command* handleView(std::stringstream& ss) {
	int taskID;
	taskID = readInteger(ss);

	validateCommand(ss);

	return new ViewTaskCommand(s, taskID);
}

static Command* handleApprove(std::stringstream& ss) {
	int taskID;
	taskID = readInteger(ss);

	validateCommand(ss);

	return new ApproveCommand(s, taskID);
}

static Command* handleDisapprove(std::stringstream& ss) {
	int taskID;
	taskID = readInteger(ss);
	MyString reason;
	ss >> reason;

	validateCommand(ss);

	return new DisapproveCommand(s, taskID, reason);
}

static Command* handleValidate(std::stringstream& ss) {
	int taskID;
	taskID = readInteger(ss);

	validateCommand(ss);

	return new ValidateCommand(s, taskID);
}

// ThirdPartyEmployee commands
static Command* handleSendCheque(std::stringstream& ss) {
	double sum;
	sum = readDouble(ss);
	MyString verificationCode;
	ss >> verificationCode;
	MyString recipientEGN;
	ss >> recipientEGN;

	validateCommand(ss);

	return new SendChequeCommand(s, sum, verificationCode, recipientEGN);
}

Command* CommandFactory(System* sPtr)
{
	s = sPtr;

	static bool skip = false; // Tova e skandalno ama inache ne znam kak da go opravq
	const int BUFF_SIZE = 1024;
	char buffer[BUFF_SIZE];
	if (!skip) {
		std::cout << ">";
	}
	std::cin.getline(buffer, BUFF_SIZE);
	std::stringstream ss(buffer);

	MyString commandStr;
	ss >> commandStr;

	if (commandStr == "") {
		skip = true;
		throw std::exception("");
	}
	else {
		skip = false;
	}
	if (commandStr == "print") {
		s->printUsers();
		throw std::exception("Nigga exception");
	}
	if (commandStr == "exit") {
		return handleExit(ss);
	}
	if (commandStr == "create_bank") {
		return handleCreateBank(ss);
	}
	if (commandStr == "login") {
		return handleLogin(ss);
	}
	if (commandStr == "signup") {
		return handleSignup(ss);
	}
	if (commandStr == "help") {
		return handleHelp(ss);
	}
	if (commandStr == "check_avl") {
		return handleCheckAvl(ss);
	}
	if (commandStr == "open") {
		return handleOpen(ss);
	}
	if (commandStr == "close") {
		return handleClose(ss);
	}
	if (commandStr == "change") {
		return handleChange(ss);
	}
	if (commandStr == "redeem") {
		return handleRedeem(ss);
	}
	if (commandStr == "list") {
		return handleList(ss);
	}
	if (commandStr == "messages") {
		return handleMessages(ss);
	}
	if (commandStr == "tasks") {
		return handleTasks(ss);
	}
	if (commandStr == "view") {
		return handleView(ss);
	}
	if (commandStr == "approve") {
		return handleApprove(ss);
	}
	if (commandStr == "disapprove") {
		return handleDisapprove(ss);
	}
	if (commandStr == "validate") {
		return handleValidate(ss);
	}
	if (commandStr == "send_cheque") {
		return handleSendCheque(ss);
	}

	throw std::logic_error("Invalid command");
}
