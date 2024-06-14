#include <iostream>
#include "MyVector.hpp"
#include "MyString.h"
	
#include "OpenTask.h"
#include "CloseTask.h"

using std::cout;
using std::cin;
using std::endl;

static const inline void nl() {
	std::cout << std::endl;
}

int main()
{
	/*Client c1("Emil", "Trifonov", "1234567890", "parola", 20, "Studenski grad");
	Client c2("Sashko", "Mandew", "1111111111", "parola", 20, "Studenski grad");
	Client c3("Denis", "Kaim", "0000000000", "parola", 20, "Studenski grad");
	Employee e("Yuliqn", "Palov", "0987654321", "dobur den", 20);
	Bank b("Bankata ot sdelka ili ne");
	b.addEmployee(e);
	OpenTask ot1(&c1, &b);
	OpenTask ot2(&c2, &b);
	OpenTask ot3(&c3, &b);
	ot1.approve();
	ot2.approve();
	b.viewAccounts();
	CloseTask ct1(&c1, &b, 100);
	CloseTask ct2(&c2, &b, 101);
	ct1.disapprove("Shte ostanem bez akaunti i tva prosto nqma kak da stane...");

	try {
		e.addTask(new OpenTask(&c1, &b));
		e.addTask(new OpenTask(&c2, &b));
		e.addTask(new OpenTask(&c3, &b));
		e.addTask(new CloseTask(&c1, &b, 100));
		e.addTask(new CloseTask(&c2, &b, 101));
	}
	catch (std::logic_error& err) { cout << err.what() << endl << endl; }

	e.viewTasks();*/
}