/* err_struct_scanf.c —— 故意写错的对照：地址加到整个结构体上
 *
 * 编译：gcc -Wall -Wextra -o err.exe err_struct_scanf.c
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

    scanf("%lf", &L);      /* 错：&L 是"整个结构的地址"，不是 double 的地址 */

    printf("%.2f\n", L.a);

    return 0;
}