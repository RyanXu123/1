#include <stdio.h>

int main(void)
{
    int i = 1;          /* 起点：循环用的变量，先给它一个开始的值 */

    while (i <= 5)      /* 条件：成立就一直转，不成立才往下走 */
    {
        printf("while 第 %d 圈\n", i);
        i = i + 1;      /* 变化：少了这一行，条件永远成立，就是死循环 */
    }

    int j = 1;          /* for 的三件事都在括号里，变量照样要先声明 */

    for (j = 1; j <= 5; j = j + 1)
    {
        printf("for 第 %d 圈\n", j);
    }

    return 0;
}
