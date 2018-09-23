//Developed by Vasylenko Kyrylo, CSIT-2
#include "triangle.h"

Triangle::Triangle(const double x1, const double y1,
	const double x2, const double y2,
	const double x3, const double y3) 
	: _a(x1,y1), _b(x2,y2), _c(x3,y3), 
	_ab(0), _bc(0), _ca(0), _ah(0), _bh(0), _ch(0), _aph(0), _bph(0), _cph(0), _am(0), _bm(0), _cm(0){}

Triangle::Triangle(const Point &a, const Point& b, const Point& c) : _a(a), _b(b), _c(c), 
	_ab(0), _bc(0), _ca(0), _ah(0), _bh(0), _ch(0), _aph(0), _bph(0), _cph(0), _am(0), _bm(0), _cm(0){}

Triangle::Triangle(const Point &a, const Segment &bc): _a(a), _b(bc.start()), _c(bc.end()), 
	_ab(0), _bc(0), _ca(0), _ah(0), _bh(0), _ch(0), _aph(0), _bph(0), _cph(0), _am(0), _bm(0), _cm(0){}

Triangle::Triangle (const Triangle& t) : _a(t.apexA()), _b(t.apexB()), _c(t.apexC()), 
	_ab(0), _bc(0), _ca(0), _ah(0), _bh(0), _ch(0), _aph(0), _bph(0), _cph(0), _am(0), _bm(0), _cm(0){}

Triangle::Triangle (const Triangle& t, bool full) : _a(t.apexA()), _b(t.apexB()), _c(t.apexC()), 
	_ab(0), _bc(0), _ca(0), _ah(0), _bh(0), _ch(0), _aph(0), _bph(0), _cph(0), _am(0), _bm(0), _cm(0)
{
	if(full) 
	{
		assignSegment(&Triangle::_ab, t);
		assignSegment(&Triangle::_bc, t);
		assignSegment(&Triangle::_ca, t);
	}
}

Triangle::~Triangle()
{
	delete _ab;
	delete _bc;
	delete _ca;
	delete _ah;
	delete _bh;
	delete _ch;
	delete _aph;
	delete _bph;
	delete _cph;
}

Triangle& Triangle::operator= (const Triangle& t)
{
	_aph = 0;
	_bph = 0;
	_cph = 0;

	_ab = 0;
	_bc = 0;
	_ca = 0;

	_ah = 0;
	_bh = 0;
	_ch = 0;

	_am = 0;
	_bm = 0;
	_cm = 0;

	_a = t.apexA();
	_b = t.apexB();
	_c = t.apexC();

	return *this;
}

double Triangle::perimeter() const
{
	return (length_a()+length_b()+length_c());
}

double Triangle::area() const
{
	return (0.5 * length_b() * height_a().length());
}

// Apexes
const Point& Triangle::apexA() const{return _a;}
const Point& Triangle::apexB() const{return _b;}
const Point& Triangle::apexC() const{return _c;}

// Segments
const Triangle::Segment& Triangle::side_a() const
{
	if(_ab==0) const_cast<Segment*>(_ab) = new Segment(_a,_b);
	return *_ab;
}
const Triangle::Segment& Triangle::side_b() const
{
	if(_bc==0) const_cast<Segment*>(_bc) = new Segment(_b,_c);
	return *_bc;
}
const Triangle::Segment& Triangle::side_c() const
{
	if(_ca==0) const_cast<Segment*>(_ca) = new Segment(_c,_a);
	return *_ca;
}

const Triangle::Segment& Triangle::side(const SidePtr p) const
{
	if((*this).*p==0) {
		if(p==&Triangle::_ab) {

			const_cast<Segment*>((*this).*p) = new Segment(_a,_b);

		} else if(p==&Triangle::_bc) {

			const_cast<Segment*>((*this).*p) = new Segment(_b,_c);

		} else if(p==&Triangle::_ca) {

			const_cast<Segment*>((*this).*p) = new Segment(_c,_a);

		}
	}

	return *((*this).*p);
}

//Task 1:
const Triangle::Segment& Triangle::median(const SidePtr side) const
{
	double x = ((*this).side(side).start().x() + (*this).side(side).end().x())/2;
	double y = ((*this).side(side).start().y() + (*this).side(side).end().y())/2;

	Point* p1 = new Point(x,y);
	Point* p2;

	if(side==&Triangle::_ab) {

		if(_bm==0){
			p2 = new Point((_b.x()+_c.x())/2,(_b.y()+_c.y())/2);
			const_cast<Segment*>(_bm) = new Segment(*p1, *p2);
		}

		return *_bm;
	} else if (side==&Triangle::_bc) {

		if(_cm==0){
		p2 = new Point((_a.x()+_c.x())/2,(_a.y()+_c.y())/2);
		const_cast<Segment*>(_cm) = new Segment(*p1, *p2);
		}

		return *_cm;
	} else if (side==&Triangle::_ca) {

		if(_am==0){
		p2 = new Point((_a.x()+_b.x())/2,(_a.y()+_b.y())/2);
		const_cast<Segment*>(_am) = new Segment(*p1, *p2);
		}

		return *_am;
	} else {
		throw "Incorrect triangle side exception";
	}
}


// Length of any segment

double Triangle::length(const SidePtr p) const
{
	return (*this).side(p).length();
};


double Triangle::length_a() const{return side_a().length();}
double Triangle::length_b() const{return side_b().length();}
double Triangle::length_c() const{return side_c().length();}

// Height points

const Triangle::Segment& Triangle::height_a() const
{
	if(_ah==0) 
	{
		if(_aph==0)
			const_cast<Point*>(_aph) = new Point((_b.x()+_c.x())/2,(_b.y()+_c.y())/2);
		const_cast<Segment*>(_ah) = new Segment(_a,*_aph);
	}
	return *_ah;
}
const Triangle::Segment& Triangle::height_b() const
{
	if(_bh==0) 
	{
		if(_bph==0)
			const_cast<Point*>(_bph) = new Point((_a.x()+_c.x())/2,(_a.y()+_c.y())/2);
		const_cast<Segment*>(_bh) = new Segment(_a,*_bph);
	}
	return *_bh;
}
const Triangle::Segment& Triangle::height_c() const
{
	if(_ch==0) 
	{
		if(_cph==0)
			const_cast<Point*>(_cph) = new Point((_a.x()+_b.x())/2,(_a.y()+_b.y())/2);
		const_cast<Segment*>(_ch) = new Segment(_a,*_cph);
	}
	return *_ch;
}

ostream& operator<<(ostream & os, const Triangle & t)
{
	os << "a = " << t.apexA() << ",b = " << t.apexB() << ",c = " << t.apexC();
	return os;
}

void Triangle::assignSegment(const SidePtr side, const Triangle& t) 
{
	if((*this).*side==0) {

		if(t.*side!=0)
			const_cast<Segment*>((*this).*side) = new Segment(*(t.*side));

	} else {
		if(t.*side == 0) {
			delete((*this).*side);
			(*this).*side=0;
		} else { 
			*((*this).*side) = *(t.*side);
		}
	}
}

Triangle::Segment& Triangle::Segment::operator=(const Segment& s)
{
	const_cast<Point&>(_a).x() = s._a.x();
	const_cast<Point&>(_a).y() = s._a.y();
	const_cast<Point&>(_b).x() = s._b.x();
	const_cast<Point&>(_b).y() = s._b.y();

	return *this;
}

ostream& operator<<(ostream & os, const Triangle::Segment& s)
{
	os << "Segment # " << s.getID()  << ", (" << s.start() << ',' << s.end() << ')' << ", lenght -> " << s.length();
	return os;
}
