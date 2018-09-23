//Developed by Vasylenko Kyrylo, CSIT-2
#include "alarm.h"

Alarm::Alarm(const Date& signalDate, const Time& signalTime, const size_t interval)
	:_signalDate(signalDate), _signalTime(signalTime),
	_interval(interval), _alive(true), _repeat(true),
	_sheduled(false), _callendar(Callendar()) {}

Alarm::~Alarm() {}

const Date& Alarm::signalDate() const { return _signalDate; }
Date& Alarm::signalDate() { return _signalDate; }
const Time& Alarm::signalTime() const { return _signalTime; }
Time& Alarm::signalTime() { return _signalTime; }
const size_t& Alarm::interval() const { return _interval; }
size_t& Alarm::interval() { return _interval; }
const bool Alarm::isAlive() const { return _alive; }
void Alarm::kill()
{
	_alive = false;
#ifndef NDEBUG
	cout << "Alarm killed" << endl;
#endif

}
const bool Alarm::repeat() const { return _repeat; }
bool& Alarm::repeat() { return _repeat; }

void Alarm::shedule(const Time& sheduleTime)
{
	_alive = false;
	_sheduled = true;
	_repeat = false;
#ifndef NDEBUG
	cout << "Alarm sheduled" << endl;
#endif
	_signalTime = _sheduleTime = sheduleTime;
	_signalDate = currentDate();
	execute();
}

void Alarm::execute()
{
	_alive = true;
	wait();
	signal();
}

void Alarm::signal()
{
	if (isAlive()) {

		if (!_sheduled || _callendar.isNotHoliday(currentDate()))
			cout << "signal" << endl;

		if (repeat()) {
			_signalDate = currentDate();
			_signalTime = currentTime(_interval);
#ifndef NDEBUG
			cout << "new executing after " << _interval << " sec" << endl;
#endif
			execute();
		}
		else if (_sheduled) {
			_signalDate = currentDate(1);//next day
#ifndef NDEBUG
			cout << "new executing at: " << _signalDate << ' ' << _signalTime << endl;
#endif
			execute();
		}

	}
}

void Alarm::wait()
{
	Date nowDate = currentDate();
	Time nowTime = currentTime();
	Time midnight(0, 0, 0);
	while (isAlive() && (nowDate != _signalDate || nowTime != _signalTime)) {
		if (nowTime == midnight) {
			++nowDate;
		}
		++nowTime;
#ifndef NDEBUG
		std::cout << "current moment -> " << nowDate << ' ' << nowTime << std::endl;
#endif
		Sleep(1000);
	}
}

void Alarm::wait(const unsigned int seconds)
{
	for (int i = 0; isAlive() && i <= seconds; ++i)
	{
		Sleep(1000);
	}
}


Date& Alarm::currentDate(const unsigned int days)
{
	time_t t = time(0);
	struct tm * now = localtime(&t);
	Date* res = new Date(now->tm_mday+days, now->tm_mon, now->tm_year + 1900);
	return *res;
}

Time& Alarm::currentTime(const unsigned int sec)
{
	time_t t = time(0);
	struct tm * now = localtime(&t);
	Time* res = new Time(now->tm_hour, now->tm_min, now->tm_sec + sec);
	return *res;
}