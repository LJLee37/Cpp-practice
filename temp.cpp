#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main(void)
{
    vector<vector<int>> arr;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            arr[i][j]=i+j;
        }
    }
    int num=0;
    for(auto i  = 0; i < arr.size(); i++)
        num += std::count(arr[i].begin(),arr[i].end(),1);
    cout << num << endl; 
}
