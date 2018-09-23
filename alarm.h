//Task 4, developed by Vasylenko Kyrylo, CSIT-2
#pragma once
#include "date.h"
#include "time.h"
#include "callendar.h"
#include <ctime>

class Alarm
{
public:
	Alarm(const Date& signalDate, const Time& signalTime, const size_t interval = 15);
	~Alarm();

	const Date& signalDate() const;
	Date& signalDate();
	const Time& signalTime() const;
	Time& signalTime();
	const size_t& interval() const;
	size_t& interval();
	const bool isAlive() const;
	const bool repeat() const;
	bool& repeat();


	void execute();
	void signal();
	void kill();
	void wait();
	void wait(const unsigned int seconds);

	void shedule(const Time& sheduleTime);

	static Date& currentDate(const unsigned int days = 0);

	//returns currentTime + sec
	static Time& currentTime(const unsigned int sec = 0);

private:
	Date _signalDate;
	Time _signalTime;
	size_t _interval;//interval of waiting for repeat in seconds
	bool _alive;
	bool _repeat;

	Time _sheduleTime;
	bool _sheduled;

	const Callendar _callendar;

};