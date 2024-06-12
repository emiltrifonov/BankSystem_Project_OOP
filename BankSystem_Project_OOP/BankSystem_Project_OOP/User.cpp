#include <iostream>
#include "User.h"
using std::cin;
using std::cout;
using std::endl;

void User::whoami() const
{
	cout << "You are " << firstName << " " << lastName << "!" << endl;
	cout << "EGN: " << egn << endl;
	cout << "Age: " << age << endl;
}