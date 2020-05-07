#include <bits/stdc++.h>
using namespace std;
int main()
{
    auto a = new int(3);
    try
    {
        delete a;
        if(a != nullptr)
            cout << "내용물 없으면 비교 가능"<< endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}