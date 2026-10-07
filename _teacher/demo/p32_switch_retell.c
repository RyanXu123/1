/* p32_switch_retell.c —— switch 从零重讲
 *
 * 同一道题写两遍：先 if / else if，再 switch。
 * 对着看，就明白 switch 是把"比同一个值"这件事换了个写法。
 */

#include <stdio.h>

int main() {
    int n;
    printf("输入 1~3：");
    scanf("%d", &n);

    /* ---------- 写法一：if / else if ---------- */
    printf("if 版：");
    if (n == 1) {
        printf("一\n");
    } else if (n == 2) {
        printf("二\n");
    } else if (n == 3) {
        printf("三\n");
    } else {
        printf("不是 1~3\n");
    }

    /* ---------- 写法二：switch ---------- */
    printf("switch 版：");
    switch (n) {
        case 1:
            printf("一\n");
            break;
        case 2:
            printf("二\n");
            break;
        case 3:
            printf("三\n");
            break;
        default:
            printf("不是 1~3\n");
            break;
    }

    return 0;
}
