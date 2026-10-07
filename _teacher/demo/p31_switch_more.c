/* p31_switch_more.c —— switch 的细节补充（配《补充_switch详解.md》）
 *
 * 第 14 讲讲了 switch 的骨架，这份把容易忽略的几条摆出来：
 *   1. 比 char 也行
 *   2. case 后面能写常量算式
 *   3. 几个 case 标签可以共用同一段
 *   4. case 里还能再嵌一个 switch
 *   5. break 只跳出 switch 这一层，外层的循环照跑
 */

#include <stdio.h>

int main() {
    /* ---------- 1. 比 char ---------- */
    char ch = 'B';

    switch (ch) {
        case 'A':
            printf("1) ch 是 A\n");
            break;
        case 'B':
            printf("1) ch 是 B\n");
            break;
        default:
            printf("1) 别的字母\n");
            break;
    }

    /* ---------- 2. case 后面写常量算式 ---------- */
    int x = 21;

    switch (x) {
        case 20 + 1:                      /* 编译器当场算成 21 */
            printf("2) 命中 case 20 + 1\n");
            break;
        default:
            printf("2) 没命中\n");
            break;
    }

    /* ---------- 3. 几个 case 共用一段 ---------- */
    int m = 4;

    switch (m) {
        case 3:
        case 4:
        case 5:
            printf("3) m 落在 3~5 里\n");
            break;
        default:
            printf("3) m 不在 3~5 里\n");
            break;
    }

    /* ---------- 4. case 里再嵌一个 switch ---------- */
    int a = 1;
    int b = 2;

    switch (a) {
        case 1:
            switch (b) {
                case 2:
                    printf("4) a = 1 且 b = 2\n");
                    break;
                default:
                    printf("4) a = 1，但 b 不是 2\n");
                    break;
            }
            break;
        default:
            printf("4) a 不是 1\n");
            break;
    }

    /* ---------- 5. break 只跳出 switch 这一层 ---------- */
    for (int i = 1; i <= 3; i++) {
        printf("5) 第 %d 轮  ", i);

        switch (i) {
            case 2:
                printf("命中 2，这一支 break 掉\n");
                break;
            default:
                printf("没命中\n");
                break;
        }

        printf("5) 第 %d 轮的后半段还在跑\n", i);   /* 循环没被 break 掉 */
    }

    return 0;
}
