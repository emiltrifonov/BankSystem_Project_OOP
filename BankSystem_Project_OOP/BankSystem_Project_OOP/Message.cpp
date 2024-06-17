#include <iostream>
#include "Message.h"

Message::Message(MyString& text, const Employee* processor) : text(text), processor(processor) { }

std::ostream& operator<<(std::ostream& os, const Message& message)
{
	return os << message.text << " ( processed by " << message.processor->getFirstName() << " "
		<< message.processor->getLastName() << " )";
}