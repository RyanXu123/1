#include <stdio.h>

/* 参数表写法：类型 + 名字，一样一样列清楚 */
int set_bit(int num, int n) {
    return num | (1 << n);
}

int main() {
    int a = 85;                     /* 0101 0101，第 1 位本来是 0 */

    printf("a = %d，第 1 位 = %d\n", a, (a >> 1) & 1);

    int b = set_bit(a, 1);          /* 调用：只写值，不写类型 */
    printf("set_bit(a, 1) = %d，第 1 位 = %d\n", b, (b >> 1) & 1);

    return 0;
}
