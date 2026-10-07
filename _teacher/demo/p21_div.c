/* p21_div.c —— 两种除法（整数除法 / 浮点除法）
   第 01 讲讲过的老东西，这次连"算完再存"那个坑一起看 */
#include <stdio.h>

int main() {
    int a = 30;
    int b = 4;

    printf("a = %d, b = %d\n", a, b);

    /* ① 整数除法：两边都是 int，结果还是 int，小数直接砍掉 */
    printf("a / b        = %d\n", a / b);        /* 7，不是 7.5，也不是 8 */

    /* ② 浮点除法：只要有一边是小数，就按小数算 */
    printf("a / 4.0      = %.1f\n", a / 4.0);    /* 7.5 */
    printf("(float)a / b = %.1f\n", (float)a / b);/* 7.5，强制转换 */

    /* ③ 坑：类型看两个操作数，不是看你要存进哪个盒子 */
    float bad  = a / b;      /* 先算整数 7，再存成 7.0 */
    float good = a / 4.0;    /* 先算 7.5，再存 */
    printf("float bad    = %.1f   <- 先整除再存，小数没了\n", bad);
    printf("float good   = %.1f\n", good);

    /* ④ 取余只对整数用：拿的是余数，不是小数部分 */
    printf("a %% b        = %d\n", a % b);       /* 2 */
    printf("7 %% 2        = %d\n", 7 % 2);       /* 1 */

    return 0;
}
