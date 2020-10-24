#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "charlist.h"

string* encrypt(time_t key, char* seed)
{
    srand(key);
    int t = 0;
    for (int i = 0; i < strlen(seed); i++)
        t += i;
    for (int i = 0; i < t; i++)
        rand();
    t = rand();
    string* retval = int_to_string(t);
    if (retval == NULL)
        return NULL;
    for (int i = 0; i < strlen(seed); i++)
    {
        srand(seed[i]);
        t = rand();
        string*temp = int_to_string(t);
        if (temp == NULL)
        {
            delete_string(&retval);
            return NULL;
        }
        add_by_move(&retval, &temp);
    }
    return retval;
}
int main()
{
    printf("your password : ");
    char password[5];
    scanf("%s", password);
    time_t current = 0;
    time(&current);
    string* encrypted = encrypt(current, password);
    printf("password : ");
    scanf("%s", password);
    string* again = encrypt(current, password);
    printf("%d\n", is_equal(encrypted, again));
    return 0;
}
