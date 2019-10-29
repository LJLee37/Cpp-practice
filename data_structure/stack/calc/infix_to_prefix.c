//check if argument infix statement is valid and returns correced statement. removes incorrect parts
void check_valid(char*[100] tar);

//converts infix to postfix. 
void convert_postfix(char*[100] tar);

/*/
typedef struct
{
    char oper;
    int prio;
} op;
/*/

const int op[6][2]={ {'+',2}, {'-',2}, {'*',3}, {'/',3}, {'(',1}, {')',1} };

#include <stdio.h>
int main()
{
    printf("This is a program to convert infix statement(ex. 3+7*2) into postfix statement(ex. 372*+).\n");
    printf("Enter your infix statement.\n");
    char numsample[11];
    for (char i = '0'; i <= '9'; i++)
        numsample[i-'0'] = i;
    char statement[100];
    scanf("%s",statement); 
    check_valid(&statement);
    convert_postfix(&statement);
    printf("Converted statement is : %s\n",statement);
    return 0;
}


