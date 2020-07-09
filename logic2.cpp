#include <iostream>
using namespace std;
int main()
{
    int cnt = 0, max = 0;
    int x = 0;
    while(!cin.fail())
    {
        if (max < x)
            max = x;
        cnt++;
        cout << "X : ";
        cin >> x;
    }
    cout << "데이터 : " << cnt << endl;
    cout << "최대값 : " << max << endl;
}
