/* p49_pointer_star.c —— 第 10 讲复习：& 和 * 到底在干嘛
 *
 * 编译：gcc -Wall -Wextra -o p49.exe p49_pointer_star.c
 */

#include <stdio.h>

int main(void)
{
    int n = 7;        /* 普通变量：格子里装 7 */
    int *p = &n;      /* 声明：p 是"指向 int 的指针"，装的是 n 那格的地址 */

    printf("n   = %d\n", n);
    printf("*p  = %d\n", *p);    /* 使用：顺着地址去开那一格，读出来 */

    *p = 42;          /* 使用：顺着地址开那一格，把 42 写进去 */
    printf("after *p = 42,\n");
    printf("n   = %d\n", n);     /* n 自己跟着变了，因为改的就是它那一格 */

    return 0;
}