/* p50_struct_review.c —— 第 19 讲复习：struct 的三个动作
 *
 * 编译：gcc -Wall -Wextra -o p50.exe p50_struct_review.c
 */

#include <stdio.h>

/* ① 画表：定义一种新类型，名字叫 struct Line */
struct Line
{
    double a;
    double b;
};

/* ③ 返回值就是"整张表打好的包" */
struct Line make_line(double a, double b)
{
    struct Line r;        /* ② 按表开一个盒子，名字叫 r */

    r.a = a;              /* 变量用点取成员 */
    r.b = b;

    return r;             /* 整个盒子交回去 */
}

int main(void)
{
    struct Line one;                 /* 先开盒子，两个成员此刻还是垃圾 */
    one.a = 3.0;
    one.b = 0.0;
    printf("one   : a = %.2f  b = %.2f\n", one.a, one.b);

    struct Line two = {2.0, 1.0};    /* 按定义顺序一次填满 */
    printf("two   : a = %.2f  b = %.2f\n", two.a, two.b);

    struct Line three = make_line(2.0, 1.0);
    printf("three : a = %.2f  b = %.2f\n", three.a, three.b);

    return 0;
}