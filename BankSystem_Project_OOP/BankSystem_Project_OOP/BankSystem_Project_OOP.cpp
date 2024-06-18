#include <iostream>
#include "MyVector.hpp"
#include "MyString.h"	
#include "OpenTask.h"
#include "CloseTask.h"
#include "System.h"

#include "User.h"
#include "Client.h"
#include "Employee.h"
#include "ThirdPartyEmployee.h"

#include "CreateBankCommand.h"
#include "ExitCommand.h"
#include "ListTasksCommand.h"

using std::cout;
using std::cin;
using std::endl;

const static void test() {
	Client c1("Emil", "Trifonov", "1234567890", "parola", 20, "Studenski grad");
	Client c2("Sashko", "Mandew", "0000000000", "parola", 20, "Studenski grad");
	Client c3("Denis", "Kaim", "0000000000", "parola", 20, "Studenski grad");
	Employee e("Yuliqn", "Palov", "0987654321", "dobur den", 20);
	Employee e2("Yuliqn", "Palov", "0987654320", "dobur den", 20);
	Bank b("Bankata ot sdelka ili ne");
	b.addEmployee(e);
	OpenTask ot1(&c1, &b);
	OpenTask ot2(&c2, &b);
	OpenTask ot3(&c3, &b);
	ot1.approve();
	ot2.approve();
	CloseTask ct1(&c1, &b, 100);
	CloseTask ct2(&c2, &b, 101);
	ct1.disapprove("Shte ostanem bez akaunti i tva prosto nqma kak da stane...");
	//CloseTask ct12(&c1, &b, 100);
	//ct12.approve();

	try {
		e.addTask(new OpenTask(&c1, &b));
		e.addTask(new OpenTask(&c2, &b));
		e.addTask(new OpenTask(&c3, &b));
		e.addTask(new CloseTask(&c1, &b, 100));
		e.addTask(new CloseTask(&c2, &b, 101));
		e2.addTask(new OpenTask(&c3, &b));
	}
	catch (std::logic_error& err) { cout << err.what() << endl << endl; }

	cout << endl;
	ct1.view();
	cout << endl;
	ct2.view();
	cout << endl;

	//e.listTasks();
	ListTasksCommand list1(e);
	list1.execute();
	cout << endl;
	//e2.listTasks();
	ListTasksCommand list2(e2);		
	list2.execute();
	cout << endl;
	//c1.showMessages();
	cout << endl;
	//c2.showMessages();

	b.viewAllAccounts();
}

int main()
{
	//test();

	try {
		MyString str;
		cin >> str;

		cout << endl << str << endl;
	}
	catch (std::exception& e) { cout << e.what() << endl; }
	catch (...) { }
}