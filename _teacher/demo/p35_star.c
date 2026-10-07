/* p35_star.c —— 想让一件事重复 k 次，就用循环数到 k
 *
 * 核心就一句：printf("*") 打一个星号；想打几个，就让 for 转几圈。
 */

#include <stdio.h>

int main() {
    /* ---------- 1. 打固定个数 ---------- */
    int k = 7;

    printf("打 %d 个星号：", k);
    for (int j = 1; j <= k; j++) {
        printf("*");            /* 注意：这里没有 \n */
    }
    printf("\n");               /* 收尾才换行 */

    /* ---------- 2. 每行个数不一样，个数是用式子算出来的 ---------- */
    printf("\n");
    for (int i = 1; i <= 3; i++) {
        int cnt = 2 * i + 1;    /* i=1 -> 3 个，i=2 -> 5 个，i=3 -> 7 个 */

        for (int j = 1; j <= cnt; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
