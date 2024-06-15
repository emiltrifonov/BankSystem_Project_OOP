#include<iostream>
#include "Message.h"

Message::Message(MyString& text, Employee* processor) : text(text), processor(processor), index(indexCounter++) { }

std::ostream& operator<<(std::ostream& os, const Message& message)
{
	return os << "[" << message.index << "] - " << message.text << " ( processed by " << message.processor->getFirstName() << " "
		<< message.processor->getLastName() << " )";
}

int Message::indexCounter = 1;