//Task 2, developed by Vasylenko Kyrylo, CSIT-2
#pragma once
#include "date.h"
#include <iostream>

class Callendar
{
public:
	Callendar(const unsigned int currentYear = 2018);
	~Callendar();
	const std::string getDay(Date& date) const;
	const bool isHoliday(Date& date) const;
	const bool isNotHoliday(Date& date) const;
	void printHolidays() const;

private:
	static std::string days[7];
	static std::string holidays[11];
	static Date holidayDates[11];
	const unsigned int _currentYear;
};

unsigned int century(unsigned int year);