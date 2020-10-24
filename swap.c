#include <stdio.h>
int main()
{
    int m, n, dummy;
    scanf("%d %d", &m, &n);
    int * p = &m;
    dummy = *p;
    p = &n;
    dummy += *p;
    *p = dummy - *p;
    dummy -= *p;
    p = &m;
    *p = dummy;
    printf("%d, %d", m, n);
}
