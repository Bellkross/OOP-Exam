//Developed by Vasylenko Kyrylo, CSIT-2
#pragma once
#include <Windows.h>
#include <iostream>
using namespace std;

class Time
{
private:

	int _hours;
	int _minutes;
	int _seconds;
	void normalizeTime();

public:

	static const double hourToDec;

	Time (unsigned int h=0, unsigned int m=0, unsigned int s=0);
	Time (const Time&);
	~Time(){};
	Time& operator=(const Time&);

	operator int() const;
	operator double() const;

	inline int hours() const {return _hours;}
	inline int minutes() const {return _minutes;}
	inline int seconds() const {return _seconds;}
	
	inline int& hours() {return _hours;}
	inline int& minutes() {return _minutes;}
	inline int& seconds() {return _seconds;}

	//Current time changing for 1 second

	const Time& operator++();

	const Time operator++(int);

	const Time& operator--();

	const Time operator--(int);

};

//Adding time intervals

double operator+(const Time&, const Time&);

ostream& operator<<(ostream&, const Time &);

bool operator==(const Time& t1, const Time& t2);

bool operator!=(const Time& t1, const Time& t2);

bool operator>(const Time& t1, const Time& t2);

bool operator<(const Time& t1, const Time& t2);

bool operator>=(const Time& t1, const Time& t2);

bool operator<=(const Time& t1, const Time& t2);