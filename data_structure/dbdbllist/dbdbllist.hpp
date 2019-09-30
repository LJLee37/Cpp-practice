#ifndef DBDBLLIST
#define DBDBLLIST
template <typename T>
class node
{
private:
	T data{};
	node* next{nullptr}, prev{nullptr};
public:
	node* next(){return next;}
	node* prev(){return prev;}
	void link_next(node* n){next=n;}
	void link_prev(node* p){prev=p;}
	void out_of_list() // Use with serious caution!
	{
		if(prev != nullptr)
			prev->link_next(next);
		if(next != nullptr)
			next->link_prev(prev);
		prev = nullptr;
		next = nullptr;
	}
	node(){}
	node(T d, node* p):
		data{d},
		prev{p}
	{prev->link_next(this);}
	node(T d, node* p, node* n):
		data{d},
		prev{p},
		next{n}
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

typedef dbdbllist list;

#endif
