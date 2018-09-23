//Developed by Vasylenko Kyrylo, CSIT-2
#include "date.h"

string Date::monthNames[12] = { "jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec" };
bool Date::defaultSet = false;
Date Date::defaultDate;

Date::Date(unsigned int d, Month m, unsigned int y)
{
	fillDate(d, m, y);
}

Date::Date(unsigned int d, unsigned int m, unsigned int y)
{
	if (m > 11) throw BadDate(d, m, y);

	fillDate(d, Month(m), y);
}

Date::Date(const Date& d)
{
	fillDate(d._day, Month(d._month), d._year);
}

Date::~Date() {}

unsigned int Date::day() const { return _day; }
Date::Month Date::month() const { return Month(_month); }
unsigned int Date::year() const { return _year; }
const string Date::getMonthName() const { return monthNames[_month]; }

void Date::setDay(unsigned int day)
{
	if (_day - 1 < 1)
	{
		if (_month < 1) {
			_month = Month(11);
			if (_year - 1 < 0) {
				_year = 0;
			}
			else {
				--_year;
			}
		}
		else {
			--_month;
		}
		day = daysInMonth(Month(_month), leapYear(_year));
	}
	else if (daysInMonth(Month(_month), leapYear(_year)) < day) {
		if (_month + 1 > 11) {
			_month = 0;
			++_year;
		}
		else {
			++_month;
		}
		day = 1;
	}
	fillDate(day, Month(_month), _year);
}

void Date::setMonth(unsigned int month)
{
	if (month > 11) throw month;

	fillDate(_day, Month(month), _year);
}

void Date::setDYear(unsigned int year)
{
	fillDate(_day, Month(_month), year);
}

void Date::setDefault(unsigned int day, Month month, unsigned int year)
{
	if (!defaultSet) {
		defaultDate = Date(day, month, year);
		defaultSet = true;
	}
	else {
		defaultDate.fillDate(day, month, year);
	}
}

void Date::setDefault()
{
	defaultSet = !defaultSet;
}

void Date::showDefault()
{
	cout << defaultSet << endl;
}

const Date& Date::operator++()
{
	setDay(_day + 1);
	return *this;
}

const Date Date::operator++(int i)
{
	Date res = Date(*this);
	++(*this);
	return res;
}

const Date& Date::operator--()
{
	setDay(_day - 1);
	return *this;
}

const Date Date::operator--(int)
{
	Date res = Date(*this);
	--(*this);
	return res;
}

bool Date::leapYear(unsigned int y) { return y % 100 == 0 ? y % 400 == 0 : y % 4 == 0; }

void Date::fillDate(unsigned int d, Month m, unsigned int y)
{

	if (d > daysInMonth(Month(m), leapYear(y)) || d < 1)
		throw BadDate(d, m, y);

	_day = d;
	_month = m;
	_year = y;

}

unsigned int Date::daysInMonth(const Month month, const bool leap)
{
	switch (month)
	{
	case 0:
	case 2:
	case 4:
	case 6:
	case 7:
	case 9:
	case 11:
		return 31;
	case 3:
	case 5:
	case 8:
	case 10:
		return 30;
	case 1:
		return leap ? 29 : 28;
	default:
		throw month;
	}
}

ostream& operator<<(ostream& os, const Date & d)
{
	os << d.day() << ' ' << d.getMonthName() << ' ' << d.year();
	return os;
}

ostream& operator<<(ostream& os, const Date::BadDate & bd)
{
	os << "Bad date: " << bd._day << ' ' << bd._month << ' ' << bd._year;
	return os;
}

bool operator==(const Date& d1, const Date& d2)
{
	return (d1.day() == d2.day() && d1.month() == d2.month() && d1.year() == d2.year());
}

bool operator!=(const Date& d1, const Date& d2)
{
	return !(d1 == d2);
}

bool operator > (const Date& d1, const Date& d2)
{
	if (d1.year() > d2.year()) return true;

	if (d1.year() == d2.year())
		return d1.month() > d2.month() ? true : d1.month() == d2.month() && d1.day() > d2.day();

	return false;
}

bool operator < (const Date& d1, const Date& d2) { return d2 > d1; }

bool operator >= (const Date& d1, const Date& d2) { return d1 > d2 || d1 == d2; }

bool operator <= (const Date& d1, const Date& d2) { return d2 >= d1; }