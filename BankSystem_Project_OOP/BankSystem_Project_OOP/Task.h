#pragma once
#include "MyString.h"

class Task {
public:
	virtual void list() const = 0;
	virtual void view() const = 0;
	virtual void approve() = 0;
	virtual void disapprove(const MyString& reason) = 0;
	//virtual void execute() const = 0;

	virtual Task* clone() const = 0;

	virtual ~Task() = default;

protected:
	//int index = 1;
};