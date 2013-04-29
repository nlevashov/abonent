#include "minilist.h"
#include "datetime.h"
#include <iostream>
//(done)float -> целый
//(done)iterator end
//сорт при выводе
struct TCall {
	long long number;
	DateTime date;
	unsigned int duration;

	TCall & operator = (const TCall & c)
	{
		number = c.number;
		date = c.date;
		duration = c.duration;
	}
};

class Abonent {
	unsigned int _traffic;
	int _balance;
	minilist<TCall> _history;

	public: 
		Abonent(unsigned int);	//traffic
		Abonent(const Abonent &);
//		~Abonent();

		Abonent & operator = (const Abonent &);

		void balance_plus(unsigned int);
		int balance();

		void call(long long, DateTime, unsigned int);	//number, date, duration

		void history();
		void history(DateTime);
		void history(long long);
};

Abonent::Abonent(unsigned int traffic) : _traffic(traffic), _balance(0) {}

Abonent::Abonent(const Abonent & a) : _traffic(a._traffic), _balance(a._balance), _history(a._history) {}

Abonent & Abonent::operator = (const Abonent & a)
{
	_traffic = a._traffic;
	_balance = a._balance;
	_history = a._history;
	return *this;
}

void Abonent::balance_plus(unsigned int money)
{
	_balance += money;
}

int Abonent::balance()
{
	return _balance;
}

void Abonent::call(long long _number, DateTime _date, unsigned int _duration)
{
	_balance -= _duration * _traffic;
	TCall temp;
	temp.number = _number;
	temp.date = _date;
	temp.duration = _duration;
	_history.push_back(temp);
}

void Abonent::history()
{
	std::cout << "History:" << std::endl;
	for (_iterator<TCall> iter = _history.begin();; iter++) {
		std::cout << iter->number << ' ' << iter->date << ' ' << iter->duration << std::endl;
		if (iter == _history.end()) break; 
	}
}

void Abonent::history(DateTime dt)
{
	std::cout << "Calls from " << dt << ':' << std::endl;
	for (_iterator<TCall> iter = _history.begin();; iter++) {
		if (iter->date == dt) std::cout << iter->number << ' ' << iter->duration << std::endl;
		if (iter == _history.end()) break; 
	}
}

void Abonent::history(long long numb)
{
	std::cout << "Calls to " << numb << ':' << std::endl;
	for (_iterator<TCall> iter = _history.begin();; iter++) {
		if (iter->number == numb) std::cout << iter->date << ' ' << iter->duration << std::endl;
		if (iter == _history.end()) break; 
	}
}
