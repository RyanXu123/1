/* p36_space_star.c —— 一行里：先空格、后星号、最后换行
 *
 * 输出的形状跟菱形无关，练的是"把空格和星号拼在一行里"这件事。
 */

#include <stdio.h>

int main() {
    int n = 7;

    for (int i = 1; i <= n; i++) {

        /* 第 1 件：先打空格，第 i 行打 n - i 个 */
        for (int j = 1; j <= n - i; j++) {
            printf(" ");          /* 引号里是"真的一个空格"，不是空串 */
        }

        /* 第 2 件：再打星号，第 i 行打 i 个 */
        for (int j = 1; j <= i; j++) {
            printf("*");
        }

        /* 第 3 件：换行。一句就够，绝不能放进上面任何一个循环里 */
        printf("\n");
    }

    return 0;
}
