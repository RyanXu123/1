#include <stdio.h>

/* ---------- 写法一：指针出参 ----------
 * 函数自己不返回结果，用两个指针把 a、b 写回调用者那两格里。
 * 跟 scanf("%d", &n) 是同一条规矩：要给出去的东西，得把地址交进去。
 */
void solve_ptr(double x1, double y1, double x2, double y2, double *pa, double *pb)
{
    double a = (y2 - y1) / (x2 - x1);
    *pa = a;                 /* 往 pa 指的那一格写 */
    *pb = y1 - a * x1;       /* 代回去求 b */
}

/* ---------- 写法二：结构体返回 ----------
 * 把 a、b 打成一个包，一次交回。
 */
struct Line
{
    double a;
    double b;
};

struct Line solve_struct(double x1, double y1, double x2, double y2)
{
    struct Line r;

    r.a = (y2 - y1) / (x2 - x1);
    r.b = y1 - r.a * x1;

    return r;
}

int main(void)
{
    /* 第一组：过 (1,3) 和 (4,12) → y = 3x + 0 */
    double x1 = 1.0, y1 = 3.0;
    double x2 = 4.0, y2 = 12.0;

    double a = 0.0, b = 0.0;
    solve_ptr(x1, y1, x2, y2, &a, &b);
    printf("set1 pointer : a = %.2f  b = %.2f\n", a, b);

    struct Line line = solve_struct(x1, y1, x2, y2);
    printf("set1 struct  : a = %.2f  b = %.2f\n", line.a, line.b);

    /* 第二组：过 (2,5) 和 (6,13) → y = 2x + 1 */
    x1 = 2.0; y1 = 5.0;
    x2 = 6.0; y2 = 13.0;

    solve_ptr(x1, y1, x2, y2, &a, &b);
    printf("set2 pointer : a = %.2f  b = %.2f\n", a, b);

    line = solve_struct(x1, y1, x2, y2);
    printf("set2 struct  : a = %.2f  b = %.2f\n", line.a, line.b);

    return 0;
}