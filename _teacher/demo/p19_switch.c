#include <stdio.h>

int main() {
    int a = 6;      /* 110 */
    int i = 0;      /* 想问第几位 */

    switch (i) {
        case 0:
            printf("第 0 位 = %d\n", a & 1);
            break;
        case 1:
            printf("第 1 位 = %d\n", (a >> 1) & 1);
            break;
        case 2:
            printf("第 2 位 = %d\n", (a >> 2) & 1);
            break;
        default:
            printf("只支持问第 0 到 2 位\n");
            break;
    }

    /* 同样的事用循环做：一个值一个值挨着走，代码更短 */
    for (int k = 2; k >= 0; k--) {
        printf("循环看第 %d 位 = %d\n", k, (a >> k) & 1);
    }

    return 0;
}
