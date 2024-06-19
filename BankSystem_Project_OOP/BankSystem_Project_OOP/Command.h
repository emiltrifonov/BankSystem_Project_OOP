#pragma once
#include "System.h"

class Command {
public:
	virtual void execute() = 0;

	virtual ~Command() = default;

protected:
	void invalidCmd() const;
};