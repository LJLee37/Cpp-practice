#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "encrypt.h"

//types
typedef enum {yegum, jeokgum, junggwon, fund}Acctype_t;
typedef struct
{
    int account_number;
    unsigned long long balance;
    Acctype_t account_type;
    time_t key;
    string * encrypted;
    char*name;
    int lenName;
}Account_t;
typedef struct node
{
    Account_t account;
    struct node * next;
}Node_t;
typedef struct
{
    Node_t * head;
    Node_t * current;
    Node_t * previous;
}List_t;


//global variables
List_t * accounts = NULL;


//function prototypes
//short addNewAccount(char*name, char[4] key, 
int saveAccounts();
int loadAccounts();
int findAccount(int account_number);
int withdraw(int money, char* passwd);
int deposit(int money);
int send(int money, int target_account_number);
int removeAcc();

//function definitions
int saveAccounts()
{
    FILE*target = fopen("accounts.txt", "w");
    Node_t * tarN = accounts->head;
    while(tarN != NULL)
    {
        int lenName = tarN->account.lenName;
        char*name = tarN->account.name;
        int accnum = tarN->account.account_number;
        unsigned long long balance = tarN->account.balance;
        Acctype_t type = tarN->account.account_type;
        time_t key = tarN->account.key;
        char * encrypted = chararrfy(tarN->account.encrypted);
        int lenEncrypted = tarN->account.encrypted->len;
        fprintf(target, "%d\n%d\n%d\n%llu\n%d\n%jd\n%s\n%s\n", lenName, lenEncrypted, accnum, balance, type, key, encrypted, name);
        tarN = tarN->next;
    }
    fclose(target);
    return 0;
}
int loadAccounts()
{
    if (accounts != NULL)
        return 1;
    FILE*read = fopen("accounts.txt", "r");
    if (read == NULL)
        return 1;
    accounts = (List_t*)malloc(sizeof(List_t));
    if (accounts == NULL)
        return 1;
    Node_t*tarN = (Node_t*)malloc(sizeof(Node_t));
    if (tarN == NULL)
        return 1;
    accounts->head = tarN;
    accounts->current = tarN;
    accounts->previous = NULL;
    while (1)
    {
        if (fscanf(read, "%d", &(tarN->account.lenName)) == EOF)
        {
            free(tarN);
            if (accounts->previous == NULL)
                accounts->head = accounts->current = NULL;
            else
            {
                accounts->previous->next = NULL;
                accounts->current = accounts->head;
                accounts->previous = NULL;
            }
            break;
        }
        tarN->account.name = (char*)malloc(sizeof(char) * tarN->account.lenName);
        if (tarN->account.name == NULL)
        {
            free(tarN);
            if (accounts->previous == NULL)
                accounts->head = accounts->current = NULL;
            else
            {
                accounts->previous->next = NULL;
                accounts->current = accounts->head;
                accounts->previous = NULL;
            }
            return 1;
        }
        int lenEncrypted;
        fscanf(read, "%d", &lenEncrypted);
        char* tempen = (char*)malloc(sizeof(char) * lenEncrypted);
        if (tempen == NULL)
        {
            free(tarN->account.name);
            free(tarN);
            if (accounts->previous == NULL)
                accounts->head = accounts->current = NULL;
            else
            {
                accounts->previous->next = NULL;
                accounts->current = accounts->head;
                accounts->previous = NULL;
            }
            return 1;
        }
        fscanf(read, "%d%llu%d", &(tarN->account.account_number), &(tarN->account.balance), &(tarN->account.account_type));
        fscanf(read, "%jd%s%s", &(tarN->account.key), tempen, tarN->account.name);
        tarN->account.encrypted = stringify(tempen);
        free(tempen);
        if (tarN->account.encrypted == NULL)
        {
            free(tarN->account.name);
            free(tarN);
            if (accounts->previous == NULL)
                accounts->head = accounts->current = NULL;
            else
            {
                accounts->previous->next = NULL;
                accounts->current = accounts->head;
                accounts->previous = NULL;
            }
            return 1;
        }
        tarN = (Node_t*)malloc(sizeof(Node_t));
        accounts->previous = accounts->current;
        accounts->current->next = tarN;
        accounts->current = tarN;
    }
    if (accounts->head == NULL)
        return 1;
    return 0;
}
int findAccount(int account_number)
{
    if (accounts->current->account.account_number == account_number)
        return 0;
    accounts->current = accounts->head;
    accounts->previous = NULL;
    while (accounts->current->account.account_number != account_number)
    {
        accounts->previous = accounts->current;
        accounts->current = accounts->current->next;
        if (accounts->current == NULL)
            return 1;
    }
    return 0;
}
int withdraw(int money, char* passwd)
{
    if (money < 0)
        return deposit(-money);
    string * encrypted = encrypt(accounts->current->account.key, passwd);
    if (is_equal(accounts->current->account.encrypted, encrypted))
        return 1;
    if (accounts->current->account.balance < money)
        return 1;
    accounts->current->account.balance -= money;
    return 0;
}
int deposit(int money)
{
    if (money < 0)
        return 1;
    accounts->current->account.balance += money;
    return 0;
}
int send(int money, int target_account_number)
{
    Node_t *from = accounts->current;
    if (findAccount(target_account_number))
        return 1;
    Node_t* to = accounts->current;
    accounts->current = from;
    printf("비밀번호 : ");
    char passwd[5];
    scanf("%s",passwd);
    if (withdraw(money, passwd))
    {
        accounts->current = to;
        return 1;
    }
    accounts->current = to;
    return deposit(money);
}
int removeAcc()
{
    if (accounts == NULL)
        return 1;
    Node_t*next = accounts->head;
    accounts->current = accounts->head;
    accounts->previous = NULL;
    while(accounts->current != NULL)
    {
        Node_t*cur = accounts->current;
        next = accounts->current->next;
        free(cur->account.encrypted);
        free(cur->account.name);
        free(cur);
        accounts->current = next;
    }
    free(accounts);
    accounts = NULL;
    return 0;
}

//main
int main()
{
    printf("기존 정보를 불러오는 중입니다...\n");
    if (loadAccounts())
    {
        printf("불러오기 실패.\n");
        removeAcc();
        return 1;
    }
    while (1)
    {
        printf("계좌번호 : ");
        int acc, money, isExit;
        scanf("%d", &acc);
        if (findAccount(acc))
        {
            printf("없는 계좌번호입니다. \n");
            continue;
        }
        printf("1. 입금, 2. 출금, 3. 송금, 4. 종료 : ");
        scanf("%d", &acc);
        char passwd[5];
        switch(acc)
        {
        case 1:
            printf("입금할 금액을 입력하세요 : ");
            scanf("%d", &money);
            if (deposit(money))
                printf("입금 성공.\n");
            else
                printf("입금 실패.\n");
            break;
        case 2:
            printf("비밀번호 : ");
            scanf("%s", passwd);
            printf("출금할 금액을 입력하세요 : ");
            scanf("%d", &money);
            if (withdraw(money, passwd))
                printf("출금 성공.\n");
            else
                printf("출금 실패.\n");
            break;
        case 3:
            printf("송금할 계좌번호를 입력하세요 : ");
            scanf("%d", &acc);
            printf("송금할 금액을 입력하세요 : ");
            scanf("%d", &money);
            if (send(money, acc))
                printf("송금 성공.\n");
            else
                printf("송금 실패.\n");
            break;
        case 4:
            break;
        default:
            printf("처음으로 돌아갑니다...");
        }
        saveAccounts();
    }
}
