//Developed by Vasylenko Kyrylo, CSIT-2
#pragma once
#include <iostream>

class Point
{
private:
	static int freeID;
	const int pointID;
	double _x;
	double _y;
public:
	Point (double x=0, double y=0);
	Point (const Point& p);
	~Point();
	Point& operator=(const Point &);
	Point& operator+=(const Point&);
	double& x();
	double& y();
	const double& x()const;
	const double& y()const;
	const int getID() const;
	static int amount();
};

std::ostream& operator<<(std::ostream&, const Point&);
const Point operator+ (const Point & u, const Point & v);
bool operator==(const Point & u, const Point &v);
bool operator!=(const Point & u, const Point &v);