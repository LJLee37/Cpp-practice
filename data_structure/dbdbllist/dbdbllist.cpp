#include "dbdbllist.hpp"

template <typename T>
bool dbdbllist<T>::first(T* d)
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

template <typename T>
bool dbdbllist<T>::next(T* d)
{
	if(cur-> next() == nullptr)
		return false;
	cur = cur-> next();
	*d = cur-> getd();
	return true;
}

template <typename T>
bool dbdbllist<T>::prev(T* d)
{
	if((cur->prev() == head)||(cur == head))
		return false;
	cur = cur-> prev();
	*d = cur-> getd();
	return true;
}

template <typename T>
void dbdbllist<T>::insert(T d)
{
	if(cur-> next() == nullptr)
		auto temp = new node<T>(d, cur);
	else
		auto temp = new node<T>(d, cur, cur-> next());
	num++;
}

template <typename T>
dbdbllist<T>::~dbdbllist()
{
	if(!first(nullptr))
		delete head;
	do
		delete cur-> prev();
	while(next(nullptr));
	delete cur;
}


