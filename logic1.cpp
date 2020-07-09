#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    for (auto i = 0; i < 10; i++)
    {
        cout << "X : ";
        int x;
        cin >> x;
        if (!(x % 2))
            n++;
    }
    cout << n << endl;
}
