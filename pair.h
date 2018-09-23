//Task 7, developed by Vasylenko Kyrylo, CSIT-2
#pragma once

template <class Key, class Value>
class Pair
{
public:
	Pair(){};
	Pair(Pair<Key, Value>& pair) : _key(pair.key()), _value(pair.value()){}
	Pair(Key key, Value value) : _key(key), _value(value) {}
	~Pair(){};
	const Key& key() const { return _key; }
	Key& key() { return _key; }
	const Value& value() const { return _value; }
	Value& value() { return _value; }
	bool operator==(const Pair<Key, Value>& pair2)
	{
		return key()==pair2.key();
	}
	bool operator!=(const Pair<Key, Value>& pair2)
	{
		return !(*this==pair2);
	}
	bool operator>(const Pair<Key, Value>& pair2)
	{
		return key() > pair2.key();
	}
	bool operator<(const Pair<Key, Value>& pair2)
	{
		return !(*this > pair2);
	}
	bool operator>=(const Pair<Key, Value>& pair2)
	{
		return (*this > pair2)||(*this == pair2);
	}
	bool operator<=(const Pair<Key, Value>& pair2)
	{
		return (*this < pair2)||(*this == pair2);
	}
private:
	Key _key;
	Value _value;
};

template <class Key,class Value>
ostream& operator<<(ostream& os,const Pair<Key,Value>& pair)
{
	os << pair.key() << " -> " << pair.value();
	return os;
}