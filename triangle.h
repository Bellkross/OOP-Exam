//Developed by Vasylenko Kyrylo, CSIT-2
#pragma once
#include "point.h"

using namespace std;

class Point;
class Triangle
{
public:
	class Segment{
	private:
		static unsigned int _freeID;
		const unsigned int _myId;
		const Point& _a;// Segment start point
		const Point& _b;// Segment end point
	public:
		Segment(const Segment&);		
		Segment(const Point &start, const Point &end);
		~Segment();

		Segment& operator=(const Segment&);
		const Point& start() const;
		const Point& end() const;

		double length () const;
		double distance (const Point&) const;
		const int getID() const;
	};
	typedef Segment* Triangle::* SidePtr;

	Triangle(const double x1=0, const double y1=0,
		const double x2=1, const double y2=0,
		const double x3=0, const double y3=1);
	Triangle(const Point &a, const Point& b, const Point& c);
	Triangle(const Point &a, const Segment &bc);
	Triangle (const Triangle&, bool);
	Triangle (const Triangle&);
	~Triangle();
	Triangle& operator= (const Triangle&);

	double perimeter() const;
	double area() const;

	// Apexes
	const Point& apexA() const;
	const Point& apexB() const;
	const Point& apexC() const;

	// Sides
	const Segment& side(const SidePtr) const;
	
	const Segment& side_a() const;
	const Segment& side_b() const;
	const Segment& side_c() const;

	// Length of any side
	double length(const SidePtr) const;

	//Task 1:
	const Segment& median(const SidePtr) const;

	double length_a() const;
	double length_b() const;
	double length_c() const;

	const Segment& height_a() const;
	const Segment& height_b() const;
	const Segment& height_c() const;

	SidePtr ab() const {return &Triangle::_ab;}
	SidePtr bc() const {return &Triangle::_bc;}
	SidePtr ca() const {return &Triangle::_ca;}

	SidePtr ah() const {return &Triangle::_ah;}
	SidePtr bh() const {return &Triangle::_bh;}
	SidePtr ch() const {return &Triangle::_ch;}

private:
	Point _a, _b, _c;
	Point *_aph, *_bph, *_cph;
	Segment *_ab, *_bc, *_ca;
	Segment *_ah, *_bh, *_ch;
	Segment *_am, *_bm, *_cm;//medians
	void assignSegment(const SidePtr, const Triangle&);
};

ostream& operator<<(ostream &, const Triangle &);

ostream& operator<<(ostream &, const Triangle::Segment &);