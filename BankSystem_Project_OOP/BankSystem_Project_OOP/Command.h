#pragma once
#include "System.h"

class Command {
public:
	virtual void execute() = 0;
	void invalidCmd() const;

	virtual ~Command() = default;
};