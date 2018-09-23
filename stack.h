//Developed by Vasylenko Kyrylo, CSIT-2
#pragma once
#include <iostream>
using namespace std;

template <class Elem>
class Stack
{
public:
	class BadStack
	{
	private:
		std::string _message;
	public:
		std::string msg() { return _message; }
		BadStack(std::string message = "Bad stack") : _message(message) {}
	};

	bool empty() const { return doEmpty(); }
	const Elem& top() const 
	{
		if(empty())
			throw BadStack("Empty stack exception");

		return doTop(); 
	};
	void pop() 
	{
		if(empty())
			throw BadStack("Empty stack exception");

		doPop(); 
#ifndef NDEBUG
		cout << "pop" << endl;
		doPrint();
#endif
	}
	void push(const Elem& e) 
	{ 
		doPush(e); 
#ifndef NDEBUG
		cout << "push: " << e << endl;
		doPrint();
#endif
	}
	int size() const { return doSize(); }
	virtual ~Stack() {};
private:
	virtual bool doEmpty() const = 0;
	virtual const Elem& doTop() const = 0;
	virtual void doPop() = 0;
	virtual void doPush(const Elem&) = 0;
	virtual int doSize() const = 0;
	virtual void doPrint() const = 0;
};
