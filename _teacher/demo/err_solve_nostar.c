/* err_solve_nostar.c —— 参数少写一个星号会怎样
 *
 * 编译：gcc -Wall -Wextra -o err.exe err_solve_nostar.c
 */

#include <stdio.h>

void solve_ptr(double x1, double y1, double x2, double y2, double *pa, double pb)
{
    double a = (y2 - y1) / (x2 - x1);

    *pa = a;
    *pb = y1 - a * x1;
}

int main(void)
{
    double a = 0.0, b = 0.0;

    solve_ptr(1.0, 3.0, 4.0, 12.0, &a, &b);
    printf("a = %.2f  b = %.2f\n", a, b);

    return 0;
}