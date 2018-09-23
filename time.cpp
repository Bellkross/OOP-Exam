//Developed by Vasylenko Kyrylo, CSIT-2
#include "Time.h"

void Time::normalizeTime()
{
	while ( _seconds < 0 ) {
		--_minutes;
		_seconds = 60 + _seconds;
	}
	while ( _minutes < 0 ) {
		--_hours;
		_minutes = 60 + _minutes;
	}
	if( _hours < 0 ) {
		_hours = 0;
	}

	unsigned int s;
	unsigned int m;
	unsigned int h;
	if( _seconds >= 60 ) {
		s = _seconds%60;
		_minutes += _seconds/60;
		_seconds = s;
	}
	if( _minutes >= 60){
		m = _minutes%60;
		_hours += _minutes/60;
		_minutes = m;
	}
	if( _hours >= 24 ){
		h = _hours%24;
		_hours = h;
	}
}

Time::Time (unsigned int h, unsigned int m, unsigned int s) : _hours(h), _minutes(m), _seconds(s) {normalizeTime();}
Time::Time (const Time& t) : _hours(t.hours()), _minutes(t.minutes()), _seconds(t.seconds()) {}

Time& Time::operator=(const Time& t)
{
	seconds() = t.seconds();
	minutes() = t.minutes();
	hours() = t.hours();
	return *this;
}

Time::operator int() const 
{
	return seconds()+(minutes()*60)+(hours()*3600);
}

Time::operator double() const
{
	return seconds()+(minutes()*60)+(hours()*3600);
}

//Заміна часового проміжку на одну секунду

const Time& Time::operator++()
{ 
	seconds()+=1; 
	normalizeTime();
	return *this;
}
const Time  Time::operator++(int)
{
	Time result(*this);
	++*this;
	normalizeTime();
	return result;
}
const Time& Time::operator--()
{
	seconds()-=1; 
	normalizeTime();
	return *this;
}
const Time  Time::operator--(int)
{
	Time result(*this);
	--*this;
	normalizeTime();
	return result;
}

double operator+(const Time& t1, const Time& t2)
{
	return Time(
		t1.seconds()+t2.seconds(),
		t1.minutes()+t2.minutes(),
		t1.hours()+t2.hours()
		);
}

ostream& operator<<(ostream& os, const Time& t)
{
	os << "h:" << t.hours() << " m:" << t.minutes() << " s:" << t.seconds();
	return os;
}

bool operator==(const Time& t1, const Time& t2)
{
	return (t1.seconds()==t2.seconds()&&
		t1.minutes()==t2.minutes()&&
		t1.hours()==t2.hours());
}
bool operator!=(const Time& t1, const Time& t2)
{
	return !(t1==t2);
}

bool operator>(const Time& t1, const Time& t2)
{
	if(t1.hours() > t2.hours()) {
		return true;
	} else if ( t1.hours() == t2.hours() ) {
		return t1.minutes() > t2.minutes() ? true : t1.minutes() == t2.minutes() && t1.seconds() > t2.seconds();
	}
	return false;
}

bool operator<(const Time& t1, const Time& t2) { return t2 > t1; }

bool operator>=(const Time& t1, const Time& t2) { return t1 > t2 || t1 == t2; }

bool operator<=(const Time& t1, const Time& t2) { return t2 >= t1; }