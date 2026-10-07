#include <stdio.h>

int main() {
    /* 6 的二进制是 110，3 是 011 */
    int a = 6;
    int b = 3;

    printf("a = %d，b = %d\n", a, b);
    printf("a & b  = %d\n", a & b);
    printf("a | b  = %d\n", a | b);
    printf("a ^ b  = %d\n", a ^ b);
    printf("a << 1 = %d\n", a << 1);
    printf("a >> 1 = %d\n", a >> 1);

    /* 看某一位：a 的位 0 是 0，位 1 是 1 */
    printf("a 的位 0 = %d\n", a & 1);
    printf("a 的位 1 = %d\n", (a >> 1) & 1);
    printf("a 的位 2 = %d\n", (a >> 2) & 1);

    /* 数灯：13 是 1101，应该有 3 盏亮着 */
    int reg = 13;
    int t = reg;        /* 留一份原值，reg 待会被自己吃掉 */
    int count = 0;

    while (t > 0) {
        if ((t & 1) == 1) {
            count = count + 1;
        }
        t = t >> 1;
    }

    printf("寄存器 %d 亮着 %d 盏灯\n", reg, count);

    return 0;
}
