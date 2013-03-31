#include "minilist.h"
#include "datetime.h"
#include <iostream>

struct TCall {
	long long number;
	DateTime date;
	float duration;

	TCall & operator = (const TCall & c)
	{
		number = c.number;
		date = c.date;
		duration = c.duration;
	}
};

class Abonent {
	float _traffic;
	float _balans;
	minilist<TCall> _history;

	public: 
		Abonent(float);	//traffic
		Abonent(const Abonent &);
//		~Abonent();

		Abonent & operator = (const Abonent &);

		void balans_plus(float);
		float balans();

		void call(long long, DateTime, float);	//number, date, duration

		void history();
		void history(DateTime);
		void history(long long);
};

Abonent::Abonent(float traffic) : _traffic(traffic), _balans(0) {} //abs не пашет

Abonent::Abonent(const Abonent & a) : _traffic(a._traffic), _balans(a._balans), _history(a._history) {}

Abonent & Abonent::operator = (const Abonent & a)
{
	_traffic = a._traffic;
	_balans = a._balans;
	_history = a._history;
	return *this;
}

void Abonent::balans_plus(float money)
{
	_balans += money;	//abs не пашет
}

float Abonent::balans()
{
	return _balans;
}

void Abonent::call(long long _number, DateTime _date, float _duration)
{
	_balans -= _duration * (_traffic / 60);
	TCall temp;
	temp.number = _number;
	temp.date = _date;
	temp.duration = _duration;
std::cout << "p1" << std::endl;
	_history.push_back(temp);
std::cout << _history.size() << std::endl;
std::cout << "p2" << std::endl;
}

void Abonent::history()
{
	_iterator<TCall> iter = _history.begin();
	for (int i = 0; i < _history.size(); i++) {
		std::cout << iter->number << ' ' << iter->date << ' ' << iter->duration << std::endl;
		iter++;
	}
}

void Abonent::history(DateTime dt)
{
	_iterator<TCall> iter = _history.begin();
	std::cout << "Calls from " << dt << ':' << std::endl;
	for (int i = 0; i < _history.size(); i++) {
		if (iter->date == dt) std::cout << iter->number << ' ' << iter->duration << std::endl;
		iter++;
	}
}

void Abonent::history(long long numb)
{
	_iterator<TCall> iter = _history.begin();
	std::cout << "Calls to " << numb << ':' << std::endl;
	for (int i = 0; i < _history.size(); i++) {
		if (iter->number == numb) std::cout << iter->date << ' ' << iter->duration << std::endl;
		iter++;
	}
}
