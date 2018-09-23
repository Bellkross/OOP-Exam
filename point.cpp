//Developed by Vasylenko Kyrylo, CSIT-2
#include <iostream>
#include "point.h"

int Point::freeID = 0;

Point::Point (double x, double y) : _x(x),_y(y),pointID(++freeID)
{
#ifndef NDEBUG
	std::cout << pointID << ": created " << this << std::endl;
#endif
}

Point::Point (const Point& p) : _x(p._x),_y(p._y),pointID(++freeID)
{
#ifndef NDEBUG
	std::cout << pointID << ": copied " << this << std::endl;
#endif
}

Point::~Point()
{
#ifndef NDEBUG
	std::cout << pointID << ": removed " << this << std::endl;
#endif
}

Point& Point::operator=(const Point &p)
{
	this->_x = p.x(); 
	this->_y = p.y(); 
	return *this;
}

Point& Point::operator+=(const Point& v) 
{
	this->x()+=v.x();
	this->y()+=v.y();
	return *this;
}


double& Point::x() {return _x;}

double& Point::y() {return _y;}

const double& Point::x()const {return _x;};

const double& Point::y()const {return _y;};

const int Point::getID() const {return pointID;};

int Point::amount() {return freeID;};


std::ostream& operator<<(std::ostream& os, const Point& p){
	os << '(' << p.x() << ',' << p.y() << ')';
	return os;
}

const Point operator+ (const Point & u, const Point & v){
	Point res(u);
	res+=v;
	return res;
}

bool operator==(const Point & u, const Point &v) {
	return (u.x()==v.x())&&(u.y()==v.y());
}

bool operator!=(const Point & u, const Point &v) {
	return !(u==v);
}