#include <stdio.h>
void bump(int *target)
{
    *target = *target + 1;
}
int main(void)
{
    int n = 3;
    int *p = &n;
    bump(p);
    printf("n=%d p_value=%d\n", n, *p);
    return 0;
}  