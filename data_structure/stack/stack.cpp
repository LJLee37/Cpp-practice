#include <iostream>
using namespace std;
#include <string>
template <typename T>
class node_t
{
private:
    T data;
    node_t* next;
public:
    T get_data()
    {
        return data;
    }
    node_t(T initData, node_t* initNext)
    {    
        data = initData;
        next = initNext;
    }
    node_t* get_next()
    {
        return next;
    }
};
template <typename T>
class stack_t
{
private:
    node_t<T>* top{nullptr};
public:
    stack_t(){}
    stack_t(T initData)
    {
        push(initData);
    }
    bool empty()
    {
        if (top == nullptr)
            return true;
        else
            return false;
    }
    void push(T data)
    {
        auto* temp = new node_t<T>(data, top);
        top = temp;
    }
    T pop()
    {
        if(top == nullptr)
            return 0;
        auto* temp = top->get_next();
        auto data = top->get_data();
        delete top;
        top = temp;
        return data;
    }
    T get_top()
    {
        if(top == nullptr)
            return 0;
        return top->get_data();
    }
    ~stack_t()
    {
        while(top != nullptr)
            pop();
    }
};
int main()
{
    cout << "Stack Program" << endl;
    cout << "Making an interger stack...";
    stack_t<int> s;
    while(true)
    {
        auto cmd = 0;
        cout << endl << "choose action" << endl;
        cout << "1: push, 2: pop, 3: get_top, 4: empty, 5: end" << endl;
        cout << "your choice : ";
        cin >> cmd;
        switch (cmd)
        {
        case 1:
            cout << "type a number : ";
            int a;
            cin >> a;
            s.push(a);
            break;
        case 2:
            cout << s.pop() << endl;
            break;
        case 3:
            cout << s.get_top() << endl;
            break;
        case 4:
            cout << s.empty() << endl;
            break;
        case 5:
            return 0;
            break;
        default:
            cout << "wrong choice." << endl;
            break;
        }
    }
}