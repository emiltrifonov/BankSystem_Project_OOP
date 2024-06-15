#pragma once
#include "Employee.h"
#include "MyString.h"

class Message {
public:
	Message(MyString& text, const Employee* processor);

	friend std::ostream& operator<<(std::ostream& os, const Message& message);

private:
	const MyString text;
	const Employee* processor;
	const int index;
	static int indexCounter;
};