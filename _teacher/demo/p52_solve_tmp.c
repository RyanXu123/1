/* p52_solve_tmp.c —— 先算到局部变量、再往指针里写：完全合法
 *
 * 编译：gcc -Wall -Wextra -o p52.exe p52_solve_tmp.c
 */

#include <stdio.h>

void solve_ptr(double x1, double y1, double x2, double y2, double *pa, double *pb)
{
    double a = (y2 - y1) / (x2 - x1);
    double b = y1 - a * x1;     /* 先在本函数里算好，放进一个临时盒子 */

    *pa = a;                    /* 再把临时盒子里的值，写进外面那一格 */
    *pb = b;
}

int main(void)
{
    double a = 0.0, b = 0.0;

    solve_ptr(1.0, 3.0, 4.0, 12.0, &a, &b);
    printf("a = %.2f  b = %.2f\n", a, b);

    solve_ptr(2.0, 5.0, 6.0, 13.0, &a, &b);
    printf("a = %.2f  b = %.2f\n", a, b);

    return 0;
}