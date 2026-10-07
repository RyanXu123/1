/* p51_struct_scanf.c —— struct 配 scanf：& 加到"成员"上
 *
 * 编译：gcc -Wall -Wextra -o p51.exe p51_struct_scanf.c
 */

#include <stdio.h>

struct Line
{
    double a;
    double b;
};

int main(void)
{
    struct Line L;

    printf("giveme a and b\n");
    scanf("%lf %lf", &L.a, &L.b);        /* 读 double 用 %lf，地址取到成员上 */

    printf("L.a = %.2f  L.b = %.2f\n", L.a, L.b);   /* 打印用 %f，不用 l */

    struct Line arr[2];                  /* 结构体数组也一样，只是多一层下标 */

    for (int i = 0; i < 2; i++)
    {
        printf("line %d: a b\n", i);
        scanf("%lf %lf", &arr[i].a, &arr[i].b);
    }

    for (int i = 0; i < 2; i++)
    {
        printf("line %d -> a = %.2f  b = %.2f\n", i, arr[i].a, arr[i].b);
    }

    return 0;
}