//Developed by Vasylenko Kyrylo, CSIT-2
#include "triangle.h"//Task 1
#include "callendar.h"//Task 2, 3
#include "alarm.h"//Task 4, 5, 6
#include "pair.h"//Task 7
#include "quickPushPriorityStack.h"//Task 8
#include "quickTopPriorityStack.h"//Task 9
#include <ctime>
#include<iostream>
using namespace std;

int main(void){
	
	//For turn off output switch Debug mode to Release
	/*I changed signature from const Segment& Triangle::median(const Segment& side) const
	to const Segment& median(const SidePtr) const; for using median method for any side of triangle.*/
	
	cout << ":::::::::::::::::::::::::::::TASK 1:::::::::::::::::::::::::::::" << endl << endl;
	cout << "For turn off debug output switch Debug mode to Release" << endl;
	cout << "I changed signature from const Segment& Triangle::median(const Segment& side) const" << endl;
	cout << "to const Segment& median(const SidePtr) const; for using median method for any side of triangle." << endl << endl;

	Triangle triangle;
	Triangle::SidePtr side_ab = triangle.ab();
	Triangle::SidePtr side_bc = triangle.bc();
	Triangle::SidePtr side_ca = triangle.ca();

	cout <<"triangle.side_a() -> "<< triangle.side_a() << endl;
	cout <<"triangle.side_b() -> "<< triangle.side_b() << endl;
	cout <<"triangle.side_c() -> "<< triangle.side_c() << endl << endl;

	cout <<"triangle.median_a() -> "<< triangle.median(side_ca) << endl;
	cout <<"triangle.median_b()-> "<< triangle.median(side_ab) << endl;
	cout <<"triangle.median_c() -> "<< triangle.median(side_bc) << endl << endl;
	cout << ":::::::::::::::::::::::::::::      :::::::::::::::::::::::::::::" << endl << endl;

	cout << ":::::::::::::::::::::::::::::TASK 2:::::::::::::::::::::::::::::" << endl << endl;
	Callendar c;
	Date nowDate = Alarm::currentDate();
	cout << "Today: " << nowDate << ',' << c.getDay(nowDate) << endl << endl;
	cout << "c.getDay(Date(1,0,2000)) (should return Saturday): ";
	cout << c.getDay(Date(1,0,2000)) << endl;
	cout << "c.getDay(Date(2,0,2017)) (should return Monday): ";
	cout << c.getDay(Date(2,0,2017)) << endl;
	cout << "c.getDay(Date(18,3,2018)) (should return Wednesday): ";
	cout << c.getDay(Date(18,3,2018)) << endl << endl;

	cout << ":::::::::::::::::::::::::::::      :::::::::::::::::::::::::::::" << endl << endl;

	cout << ":::::::::::::::::::::::::::::TASK 3:::::::::::::::::::::::::::::" << endl << endl;

	Callendar ch(2018);
	cout << "holidays for current(2018) year: " << endl;
	ch.printHolidays();

	cout << endl << ":::::::::::::::::::::::::::::      :::::::::::::::::::::::::::::" << endl << endl;

	cout << ":::::::::::::::::::::::::::::TASK 4,5,6:::::::::::::::::::::::::::::" << endl << endl;

	cout << "Unfortunately, I can demonstrate work of this tasks only on the lesson, because this tasks requires using std::thread" << endl;

	cout << "But you can see realization of this tasks in alarm.h" << endl;

	cout << "And you can see code of test program in this main.cpp file, at lines 66 .. 125." << endl;

	/*
	Tesing code for tasks 4,5,6:

	#include "alarm.h"
	#include <thread>
	#include <iostream>
	using namespace std;

	void executeAlarm(Alarm* alarm) {

		alarm->execute();
	}

	void stopAlarm(Alarm* alarm) {
		alarm->kill();
	}

	void sheduleAlarm(Alarm* alarm) {
		alarm->shedule(Alarm::currentTime(5));
	}

	int main(void)
	{

		cout << ":::::::::::::::::::::::::::::TASK 4,5,6:::::::::::::::::::::::::::::" << endl << endl;

		cout << "Normal alarm: " << endl << endl;

		Alarm* alarm = new Alarm(Alarm::currentDate(), Alarm::currentTime(5));

		std::thread ath1(executeAlarm, alarm);

		Sleep(7000);

		std::thread ath2(stopAlarm, alarm);

		ath1.join();
		ath2.join();

		delete alarm;

		cout << endl << "Sheduled alarm: " << endl << endl;

		alarm = new Alarm(Alarm::currentDate(), Alarm::currentTime(5));

		std::thread ath3(sheduleAlarm, alarm);

		Sleep(8000);

		std::thread ath4(stopAlarm, alarm);

		ath3.join();
		ath4.join();

		cout << endl << ":::::::::::::::::::::::::::::          :::::::::::::::::::::::::::::" << endl << endl;

		return 0;
	}

	*/

	cout << endl << ":::::::::::::::::::::::::::::      :::::::::::::::::::::::::::::" << endl << endl;

	cout << ":::::::::::::::::::::::::::::TASK 7:::::::::::::::::::::::::::::" << endl << endl;

	Pair<int, string> pair1(1,"string1");
	Pair<int, string> pair2(2,"string2");
	Pair<int, string> pair3(3,"string3");

	cout << "pair1 > pair2 : " << (pair1 > pair2) << endl;
	cout << "pair1 < pair2 : " << (pair1 < pair2) << endl;

	cout << "pair1: " << pair1 << endl << "pair2: " << pair2 << endl << "pair3: " << pair3 << endl;

	cout << endl << ":::::::::::::::::::::::::::::      :::::::::::::::::::::::::::::" << endl << endl;

	cout << ":::::::::::::::::::::::::::::TASK 8:::::::::::::::::::::::::::::" << endl << endl;

	QuickPushPriorityStack<int, std::string> qpps;

	cout << "quick push priority stack: " << endl;

	cout << endl << endl;

	qpps.push(Pair<int, std::string>(1,"string1"));
	qpps.push(Pair<int, std::string>(2,"string2"));
	qpps.push(Pair<int, std::string>(1,"string3"));

	cout << endl << "qpps.top(): " << qpps.top() << endl << endl;

	qpps.push(Pair<int, std::string>(10,"string4"));
	qpps.push(Pair<int, std::string>(1,"string5"));
	qpps.push(Pair<int, std::string>(1,"string6"));

	cout << endl << "qpps.top(): " << qpps.top() << endl << endl;

	qpps.pop();
	qpps.pop();
	qpps.pop();

	cout << endl << "qpps.top(): " << qpps.top() << endl << endl;

	qpps.pop();
	qpps.pop();
	qpps.pop();

	try{
	cout << endl << "qpps.top(): " << qpps.top() << endl << endl;
	}catch (Stack<Pair<int,std::string>>::BadStack bs)
	{
		cout << bs.msg() << endl;
	}

	cout << endl << endl;

	try{
		qpps.pop();
	}catch (Stack<Pair<int,std::string>>::BadStack bs)
	{
		cout << bs.msg() << endl;
	}

	cout << endl << ":::::::::::::::::::::::::::::      :::::::::::::::::::::::::::::" << endl << endl;

	cout << ":::::::::::::::::::::::::::::TASK 9:::::::::::::::::::::::::::::" << endl << endl;

	QuickTopPriorityStack<int, std::string> qtps;

	cout << "quick push priority stack: " << endl;

	cout << endl << endl;

	qtps.push(Pair<int, std::string>(1,"string1"));
	qtps.push(Pair<int, std::string>(2,"string2"));
	qtps.push(Pair<int, std::string>(1,"string3"));

	cout << endl << "qtps.top(): " << qtps.top() << endl << endl;

	qtps.push(Pair<int, std::string>(10,"string4"));
	qtps.push(Pair<int, std::string>(1,"string5"));
	qtps.push(Pair<int, std::string>(1,"string6"));

	cout << endl << "qtps.top(): " << qtps.top() << endl << endl;

	qtps.pop();
	qtps.pop();
	qtps.pop();

	cout << endl << "qtps.top(): " << qtps.top() << endl << endl;

	qtps.pop();
	qtps.pop();
	qtps.pop();

	try{
	cout << endl << "qtps.top(): " << qtps.top() << endl << endl;
	}catch (Stack<Pair<int,std::string>>::BadStack bs)
	{
		cout << bs.msg() << endl;
	}

	cout << endl << endl;

	try{
		qpps.pop();
	}catch (Stack<Pair<int,std::string>>::BadStack bs)
	{
		cout << bs.msg() << endl;
	}

	cout << endl << ":::::::::::::::::::::::::::::      :::::::::::::::::::::::::::::" << endl << endl;

	cout << ":::::::::::::::::::::::::::::TASK 10:::::::::::::::::::::::::::::" << endl << endl;

	cout << "Task 10 -> linkedPriorityStack.h" << endl;

	cout << endl << ":::::::::::::::::::::::::::::Thank you for attention!:::::::::::::::::::::::::::::" << endl << endl;

	return 0;
}