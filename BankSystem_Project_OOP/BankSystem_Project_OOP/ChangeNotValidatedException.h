#pragma once
#include <iostream>
#include <exception>
#include "MyString.h"

class ChangeNotValidatedException : public std::logic_error {
public:
    ChangeNotValidatedException() : std::logic_error("Change has not been validated") { }

    explicit ChangeNotValidatedException(const MyString& message) : std::logic_error(message.c_str()) { }
};
