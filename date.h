//Developed by Vasylenko Kyrylo, CSIT-2
#pragma once
#include<string>
#include<iostream>
#include<cmath>

using namespace std;

class Date
{
public:
	struct BadDate;
	enum Month { jan = 0, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
	Date(unsigned int d = 1, Month m = Month(0), unsigned int y = 0);
	Date(unsigned int d, unsigned int m, unsigned int y);
	Date(const Date&);
	~Date();
	unsigned int day() const;
	Month month() const;
	unsigned int year() const;
	const string getMonthName() const;
	void setDay(unsigned int);
	void setMonth(unsigned int);
	void setDYear(unsigned int);
	static void setDefault(unsigned int, Month, unsigned int);
	static void setDefault();
	static void showDefault();
	const Date& operator++();
	const Date  operator++(int);
	const Date& operator--();
	const Date  operator--(int);
	static bool leapYear(unsigned int y);
	static unsigned int daysInMonth(const Month month, const bool leap);
private:
	unsigned int _day, _month, _year;
	void fillDate(unsigned int d, Month m, unsigned int y);
	static string monthNames[12];
	static bool defaultSet;
	static Date defaultDate;
};

ostream& operator<<(ostream& os, const Date & d);

struct Date::BadDate
{
	int _day, _month, _year;
	BadDate(int d, int m, int y) :_day(d), _month(m), _year(y) {};
};

ostream& operator<<(ostream& os, const Date::BadDate & bd);

bool operator==(const Date& d1, const Date& d2);

bool operator!=(const Date& d1, const Date& d2);

bool operator>(const Date& d1, const Date& d2);

bool operator<(const Date& d1, const Date& d2);

bool operator>=(const Date& d1, const Date& d2);

bool operator<=(const Date& d1, const Date& d2);