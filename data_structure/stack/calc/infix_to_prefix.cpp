#include <iostream>
#include <string>
#include <stack>
using namespace std;


//check if argument infix statement is valid and returns correced statement. removes incorrect parts
void check_valid(string& stm);

//converts infix to postfix. 
void convert_postfix(string& stm);

/*/
typedef struct
{
    char oper;
    int prio;
} op;
/*/

const int op[6][2]={ {'+',2}, {'-',2}, {'*',3}, {'/',3}, {'(',1}, {')',1} };


int main()
{
    cout << "This is a program to convert infix statement(ex. 3+7*2) into postfix statement(ex. 372*+).\n";
    cout << "Enter your infix statement.\n";
    string statement;
    cin >> statement;
    check_valid(&statement);//Error
    convert_postfix(&statement);//Error
    cout << "Converted statement is : " << statement << endl;
    return 0;
}

void check_valid(string& stm)
{
    char numsample[11];
    for (char i = '0'; i <= '9'; i++)
        numsample[i-'0'] = i;
    
}
