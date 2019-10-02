#include <cinttypes>
#ifndef DBDBLLIST
#define DBDBLLIST
template <typename T>
class node
{
private:
	T data{};
	node* next_{nullptr};
       	node* prev_{nullptr};
public:
	node* next(){return next_;}
	node* prev(){return prev_;}
	void link_next(node* n){next_=n;}
	void link_prev(node* p){prev_=p;}
	void out_of_list() // Use with serious caution!
	{
		if(prev_ != nullptr)
			prev_->link_next(next_);
		if(next_ != nullptr)
			next_->link_prev(prev_);
		prev_ = nullptr;
		next_ = nullptr;
	}
	node(){}
	node(T d, node* p):
		data{d},
		prev_{p}
	{prev_->link_next(this);}
	node(T d, node* p, node* n):
		data{d},
		prev_{p},
		next_{n}
	{
		prev_->link_next(this);
		next_->link_prev(this);
	}
	~node()
	{
		out_of_list();
	}
	T getd(){return data;}
};

template <typename T>
class dbdbllist
{
private:
	node<T>* head{};
       	node<T>* cur{};
	uint16_t num{0};
public:
	dbdbllist()
	{
		head = new node<T>;
		cur = head;
	}
	bool first(T* d);
	bool next(T* d);
	bool prev(T* d);
	auto count(){return num;}
	~dbdbllist()
	{
		if(!first(nullptr))
			delete head;
		do
			delete cur-> prev();
		while(next(nullptr));
		delete cur;
	}
	void insert(T d);
};

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

#endif
