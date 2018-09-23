//Developed by Vasylenko Kyrylo, CSIT-2
#include "triangle.h"
#include <cmath>
#include <iostream>

using namespace std;

unsigned int Triangle::Segment::_freeID = 0;

Triangle::Segment::Segment(const Point &start, const Point &end) : _a(start), _b(end), _myId(++_freeID)
{
#ifndef NDEBUG
	std::cout << _myId << ": created " << this << std::endl;
#endif
};
Triangle::Segment::Segment(const Segment& s): _a(s._a), _b(s._b),_myId(++_freeID)
{
#ifndef NDEBUG
	cout<<_myId<<": a Segment was copied";
#endif
};

Triangle::Segment::~Segment() 
{
#ifndef NDEBUG
	std::cout << _myId << ": removed " << this << std::endl;
#endif
};

const Point& Triangle::Segment::start() const {return _a;}
const Point& Triangle::Segment::end() const {return _b;}

// Segment length computation
double Triangle::Segment::length() const 
{
	double result = sqrt(pow(_b.x()-_a.x(),2)+pow(_b.y()-_a.y(),2));
	return result;
}
// Distance from segment to point computation
double Triangle::Segment::distance (const Point& p) const 
{
	double result = abs( (_b.y()-_a.y())*p.x() - (_b.x()-_a.x())*p.y() + _b.x()*_a.y() - _b.y()*_a.x() );
	result /= sqrt(pow(_b.x()-_a.x(),2)+pow(_b.y()-_a.y(),2));
	return result;
}

const int Triangle::Segment::getID() const
{
	return _myId;
}