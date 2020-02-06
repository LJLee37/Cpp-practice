#include "dbdbllist.hpp"

bool list::first(T* d)
{
	cur = head-> next();
	if(cur == nullptr)
		return false;
	else
	{
		*d = cur->getd();
		return true;
	}
}

bool list::next(T* d)
{
	if(cur-> next() == nullptr)
		return false;
	cur = cur-> next();
	*d = cur-> getd();
	return true;
}

bool list::prev(T* d)
{
	if((cur->prev() == head)||(cur == head))
		return false;
	cur = cur-> prev();
	*d = cur-> getd();
	return true;
}

void list::insert(T d)
{
	if(cur-> next() == nullptr)
		auto temp = new node<T>(d, cur);
	else
		auto temp = new node<T>(d, cur, cur-> next());
}

list::~list()
{
	if(!first(nullptr))
		delete head;
	do
		delete cur-> prev();
	while(next(nullptr));
	delete cur;
}


