//Developed by Vasylenko Kyrylo, CSIT-2
#include "callendar.h"

std::string Callendar::days[7] = { "Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday" };
std::string Callendar::holidays[11] = {
	"New Year",
	"Christmas",
	"March 8",
	"Easter",
	"Labor Day",
	"Victory Day",
	"Trinity",
	"Constitution Day of Ukraine",
	"Independence Day of Ukraine",
	"Day of the defender of Ukraine",
	"Christmas (Catholic)"
};
Date Callendar::holidayDates[11] = {
	Date(1,0,2018),	 //New Year
	Date(7,0,2018),	 //Christmas
	Date(8,2,2018),	 //March 8
	Date(8,3,2018),	 //Easter 
	Date(1,4,2018),	 //Labor Day
	Date(9,4,2018),	 //Victory Day
	Date(27,4,2018), //Trinity
	Date(28,5,2018), //Constitution Day of Ukraine
	Date(24,7,2018), //Independence Day of Ukraine
	Date(14,9,2018), //Day of the defender of Ukraine
	Date(25,11,2018) //Christmas (Catholic)
};

Callendar::Callendar(const unsigned int currentYear) : _currentYear(currentYear){}
Callendar::~Callendar() {}

const std::string Callendar::getDay(Date& date) const
{
	unsigned int y = date.year();
	unsigned int m = date.month() + 1;
	if (m == 1 || m == 2) {
		m += 12;
		y -= 1;
	}
	unsigned int c = century(y);
	unsigned int d = date.day();
	unsigned int result = (d + (((m + 1) * 13) / 5) + (y % 100) + ((y % 100) / 4) + (c / 4) + 5 * c) % 7;

	return days[result];
}

const bool Callendar::isHoliday(Date& date) const
{
	for (int i = 0; i < 11; ++i)
		if (date == holidayDates[i])
			return true;

	return false;
}

const bool Callendar::isNotHoliday(Date& date) const
{
	return !isHoliday(date);
}


unsigned int century(unsigned int year)
{
	return year / 100;
}

void Callendar::printHolidays() const
{
		for(int i = 0; i < 11; ++i)
		{
			cout << holidayDates[i] << " -> " << holidays[i] << endl;
		}
}
