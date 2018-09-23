//Task 8, developed by Vasylenko Kyrylo, CSIT-2
#pragma once
#include "linkedPriorityStack.h"

template <class Key, class Value>
class QuickPushPriorityStack : virtual public LinkedPriorityStack<Key,Value>
{
public:
	QuickPushPriorityStack(){};
	~QuickPushPriorityStack() {};
	
	//O(n)
	void doPop()
	{
		Pair<Key, Value>* topPair = &_top->_pair;
		Node* topPtr = _top;
		Node* tmpPtr = _top;

		while (tmpPtr->_next != 0)
		{
			tmpPtr = tmpPtr->_next;
			if (tmpPtr->_pair > *topPair)
			{
				topPair = &tmpPtr->_pair;
				topPtr = tmpPtr;
			}
		}

		if (topPtr == _top)
			_top = topPtr->_next;
		else
			topPtr->_prev->_next = topPtr->_next;

		if (topPtr->_next != 0)
			topPtr->_next->_prev = topPtr->_prev;

		delete topPtr;
		--_size;
	}

	//O(1)
	void doPush(const Pair<Key, Value>& pair)
	{
		Node * node = new Node(_top, 0);
		node->_pair = pair;
		if (_size > 0)
			_top->_prev = node;
		_top = node;
		++_size;
	}
};