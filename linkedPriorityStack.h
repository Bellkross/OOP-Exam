//Task 10, developed by Vasylenko Kyrylo, CSIT-2
#pragma once
#include <string>
#include "stack.h"
#include "pair.h"
#include <iostream>
using namespace std;

template <class Key, class Value>
class LinkedPriorityStack : virtual public Stack<Pair<Key, Value>>
{
public:
	LinkedPriorityStack() : _top(0), _size(0) {}
	virtual ~LinkedPriorityStack() {}
	void doPrint() const
	{
		if(empty()) {
			cout << "[];" << endl;
			return;
		}

		Node* tmp = _top;
		cout << '[';
		cout << tmp->_pair << ((tmp->_next!=0) ? ", " : "");
		while(tmp->_next!=0)
		{
			tmp = tmp->_next;
			cout << tmp->_pair << ((tmp->_next!=0) ? ", " : "");
		}
		cout << "];" << endl;
	}
protected:
	int _size;
	struct Node
	{
		Node(Node* next = 0, Node* prev = 0)
			: _next(next), _prev(prev) {};
		Pair<Key, Value> _pair;
		Node * _next;
		Node * _prev;
	};
	Node * _top;
	bool doEmpty() const { return _top == 0; };
	int doSize() const { return _size; };
	const Pair<Key, Value>& doTop() const 
	{
		return _top->_pair; 
	}
	virtual void doPop() = 0;
	virtual void doPush(const Pair<Key, Value>& value) = 0;
};