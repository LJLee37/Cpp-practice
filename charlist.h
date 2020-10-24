#ifndef __CHARLISTH__
#define __CHARLISTH__
#include <stdlib.h>
struct s_node_ch
{
    char data;
    struct s_node_ch * next;
};
typedef struct s_node_ch _nch_;
typedef struct
{
    _nch_ * first;
    _nch_ * last;
    int len;
}string;
char * chararrfy(string * target)
{
    char* retval = (char*)malloc((target->len + target->last->data == '\0') * sizeof(char));
    if (retval == NULL)
        return NULL;
    _nch_ * current = target->first;
    for (int i = 0; i < target->len; i++)
    {
        retval[i] = current->data;
        current = current->next;
    }
    if (retval[target->len - 1] != '\0')
        if (retval[target->len] != '\0') // segv possible. warning.
            retval[target->len] = '\0';
    return retval;
}
string * init_string()
{
    string* retval = (string*)malloc(sizeof(string));
    if (retval == NULL)
        return NULL;
    retval->first = NULL;
    retval->last = NULL;
    retval->len = 0;
    return retval;
}
int append_char(string* str, char ch)
{
    _nch_* newNode = (_nch_*)malloc(sizeof(_nch_));
    if (newNode == NULL) return 1;
    newNode->data = ch;
    if (str->len == 0)
    {
        str->first = newNode;
    }
    else
    {
        str->last->next = newNode;
    }
    str->len++;
    str->last = newNode;
    return 0;
}
int delete_string(string ** target)
{
    _nch_ * current = (*target)->first;
    _nch_ * next;
    while(current != NULL)
    {
        next = current->next;
        free (current);
        current = next;
    }
    free(*target);
    return 0;
}
string* stringify(char*target)
{
    string* retval = (string*)malloc(sizeof(string));
    if (retval == NULL)
        return NULL;
    for (int i = 1; target[i] != '\0'; i++)
    {
        int error = append_char(retval, target[i]);
        if(error)
        {
            delete_string(&retval);
            return NULL;
        }
    }
    return retval;
}
string * int_to_string(const int target)
{
    int size = 1;
    for (int i = 10; target / i; i *= 10)
        size++;
    _nch_ * arr = (_nch_*)malloc(size * sizeof(_nch_));
    if (arr == NULL)
        return NULL;
    int temp = target;
    for (int i = size - 1; i > -1; i--)
    {
        arr[i].data = temp / 10;
        if (i == (size - 1))
            arr[i].next = NULL;
        else
            arr[i].next = arr + i + 1;
        temp /= 10;
    }
    string* retval = (string*)malloc(sizeof(string));
    if (retval == NULL)
    {
        free(arr);
        return NULL;
    }
    retval->first=arr;
    retval->last = arr + size - 1;
    retval->len = size;
    return retval;
}
string* add_by_move(string** lhs, string** rhs)
{
    (*lhs)->last->next = (*rhs)->first;
    (*lhs)->len += (*rhs)->len;
    free((*rhs));
    *rhs = NULL;
    rhs = NULL;
    return *lhs;
}
/*
string* add_by_create(string* lhs, string* rhs)
{
*/
int is_equal(string*lhs, string*rhs)
{
    if (lhs == NULL || rhs == NULL)
        return 0;
    _nch_*cur1 = lhs->first, *cur2 = rhs->first;
    for (int i = 0; i < lhs->len; i++)
    {
        if (cur1->data != cur2->data)
            return 0;
        if (cur2->next == NULL)
        {
            if(cur1->next == NULL || cur1->next->data == '\0')
                return 1;
            else
                return 0;
        }
        if (cur1->next == NULL)
        {
            if (cur2->next->data == '\0')
                return 1;
            else
                return 0;
        }
    }
    return 1;
}


#endif
