#pragma GCC diagnostic ignored "-Wc++11-extensions"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    cout << "Destination to file : ";
    string dest;
    cin >> dest;
    ofstream file(dest);
    file << "num1 = int(input(\"num1 : \"))" << endl;
    file << "sign = input(\"sing : \")" << endl;
    file << "num2 = int(input(\"num2 : \"))" << endl;
    char opers[] = {'+','-','*','/'};
    for (auto i : opers)
    {
        for (auto j = 1; j < 10; j++)
        {
            for ( auto k = 1; k < 10; k++)
            {
                file << "if num1 == " << j << " and sign == \'" << i << "\' and num2 == " << k << ":" << endl;
                file << "    print(\"" << j << i << k << " = ";
                switch(i)
                {
                case '+':
                    file << j + k;
                    break;
                case '-':
                    file << j - k;
                    break;
                case '*':
                    file << j * k;
                    break;
                case '/':
                    file << j / k;
                    break;
                }
                file << "\")" << endl;
            }
        }
    }
    file.close();
}
