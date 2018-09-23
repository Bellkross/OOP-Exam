//Task 9, developed by Vasylenko Kyrylo, CSIT-2
#pragma once
#include "linkedPriorityStack.h"

template <class Key, class Value>
class QuickTopPriorityStack : virtual public LinkedPriorityStack<Key,Value>
{
public:
	QuickTopPriorityStack(){};
	~QuickTopPriorityStack(){};

	//O(1)
	void doPop()
	{
		Node* tmpPtr = _top;
		_top = tmpPtr->_next;
		if(tmpPtr->_next!=0)
			_top->_prev = 0;
		delete tmpPtr;
	}

	//O(n)
	void doPush(const Pair<Key, Value>& pair)
	{
		Node * node = new Node();
		node->_pair = pair;
		if(_size==0)
		{
			_top = node;
			++_size;
			return;
		}
		if(node->_pair >= _top->_pair)
		{
			_top->_prev = node;
			node->_next = _top;
			_top = node;
			++_size;
			return;
		}
		Node* tmpPtr = _top;

		while(tmpPtr->_next!=0)
		{
			tmpPtr = tmpPtr->_next;
			if(node->_pair >= tmpPtr->_pair)
			{
				node->_next = tmpPtr;
				if(tmpPtr->_prev!=0){
					tmpPtr->_prev->_next = node;
				}
				node->_prev = tmpPtr->_prev;
				tmpPtr->_prev = node;

				tmpPtr = node;

				++_size;
				return;
			}
		}
		tmpPtr->_next = node;
		node->_prev = tmpPtr;
		node->_next = 0;
	}
};