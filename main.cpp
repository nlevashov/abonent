#include "abonent.h"
#include <iostream>
using namespace std;

int main()
{
//	while (1) {
		Abonent a(1);
		cout << a.balance() << endl;
		a.balance_plus(10);
		cout << a.balance() << endl;
		a.balance_plus(20);
		cout << a.balance() << endl;

		a.call(89060739874, DateTime::get_current(), 10);
		cout << "call" << a.balance() << endl;

		Abonent b = a;
		cout << b.balance() << endl;

		b.call(89999999999, DateTime::get_current(), 5);

		cout << a.balance() << endl;
		cout << b.balance() << endl;

		Abonent c(1);
		c = a;

		a.call(23423423, DateTime::get_current(), 32);
		cout << a.balance() << endl;
		cout << c.balance() << endl;

		a.call(12312312323, DateTime::get_current(), 12);
		a.call(89060739874, DateTime(2001, 2, 14), 15);
		a.call(13242342222, DateTime(2000, 1, 1), 50);
		a.call(89060739874, DateTime::get_current(), 34);
		a.call(12312312323, DateTime(2012, 1, 12), 35);
		a.call(89060739874, DateTime::get_current(), 34);
		a.call(12312312323, DateTime(2012, 1, 12), 35);
		a.call(89060739874, DateTime::get_current(), 34);
		a.call(12312312323, DateTime(2012, 1, 12), 35);
		a.call(89060739874, DateTime::get_current(), 34);
		a.call(12312312323, DateTime(2012, 1, 12), 35);

		a.history();
		a.history(DateTime::get_current());
		a.history(89060739874);
		a.history(12312312323);
//	}

	return 0;
}
