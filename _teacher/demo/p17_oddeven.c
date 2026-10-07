#include <stdio.h>

int main() {
    /* 7 的二进制是 111，最后一位是 1 */
    int n = 7;
    printf("n = %d\n", n);
    printf("n & 1 = %d\n", n & 1);
    if ((n & 1) == 1) {
        printf("%d 是奇数\n", n);
    } else {
        printf("%d 是偶数\n", n);
    }

    /* 8 的二进制是 1000，最后一位是 0 */
    n = 8;
    printf("n = %d\n", n);
    printf("n & 1 = %d\n", n & 1);
    if ((n & 1) == 1) {
        printf("%d 是奇数\n", n);
    } else {
        printf("%d 是偶数\n", n);
    }

    return 0;
}
