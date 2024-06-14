#pragma once

unsigned getID() {
	static unsigned ID = 100;
	return ID++;
}