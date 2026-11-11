#include <stdio.h>

int main(void)
{
    int a[4] = {10, 20, 30, 40};
    int *p = a;

    printf("a[0]=%d, *p=%d\n", a[0], *p);
    printf("a[1]=%d, *(p+1)=%d\n", a[1], *(p + 1));
    printf("a[2]=%d, p[2]=%d\n", a[2], p[2]);
    printf("&a[3] - &a[1] = %d\n", (int)(&a[3] - &a[1]));

    p++;
    printf("after p++, *p=%d\n", *p);
    return 0;
}