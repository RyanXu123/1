#include <stdio.h>

int main() {
    int n = 13;

    /* 拆十进制每位：% 10 拿末位，/ 10 丢掉末位 */
    int t = n;
    printf("%d 的十进制各位是：", n);
    while (t > 0) {
        int digit = t % 10;
        printf("%d ", digit);
        t = t / 10;
    }
    printf("（从右往左读）\n");

    /* 拆二进制每位：同一招，把 10 换成 2 */
    t = n;
    printf("%d 的二进制各位是：", n);
    while (t > 0) {
        int bit = t % 2;
        printf("%d ", bit);
        t = t / 2;
    }
    printf("（从右往左读，倒过来就是 1101）\n");

    /* 十进制 15 和十六进制 0x0F 是同一个数 */
    int a = 15;
    int b = 0x0F;
    printf("a = %d，b = %d，是否相等：%d\n", a, b, a == b);

    return 0;
}
