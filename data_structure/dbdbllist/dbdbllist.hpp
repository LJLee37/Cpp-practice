#include <cinttypes>
#ifndef DBDBLLIST
#define DBDBLLIST
template <typename T>
class node
{
private:
	T data{};
	node* next_{nullptr}, prev_{nullptr};
public:
	node* next(){return next_;}
	node* prev(){return prev_;}
	void link_next(node* n){next_=n;}
	void link_prev(node* p){prev_=p;}
	void out_of_list() // Use with serious caution!
	{
		if(prev_ != nullptr)
			prev->link_next(next);
		if(next_ != nullptr)
			next->link_prev(prev);
		prev_ = nullptr;
		next_ = nullptr;
	}
	node(){}
	node(T d, node* p):
		data{d},
		prev_{p}
	{prev->link_next(this);}
	node(T d, node* p, node* n):
		data{d},
		prev_{p},
		next_{n}
	{
		prev->link_next(this);
		next->link_prev(this);
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
	node<T>* head{}, cur{};
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
	~dbdbllist();
	void insert(T d);
};

typedef dbdbllist<T> list<typename T>;

#endif
