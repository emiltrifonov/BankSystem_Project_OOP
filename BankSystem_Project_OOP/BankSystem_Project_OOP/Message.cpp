#include <iostream>
#include "Message.h"
#include "Employee.h"

Message::Message(MyString& text, const Employee* processor) : text(text), processor(processor) { }

std::ostream& operator<<(std::ostream& os, const Message& message)
{
	os << message.text;

	if (message.processor) {
		os << " (processed by " << message.processor->getFirstName() << " "
			<< message.processor->getLastName() << ").";
	}

	return os;
}