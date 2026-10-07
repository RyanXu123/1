#include <stdio.h>

int main() {
    int a = 6;

    printf("a 当成数看是 %d\n", a);
    printf("a 当成位看是 ");

    /* 从第 31 位一路看到第 0 位：先右移把要看的位送到最右边，再用 & 1 取出来 */
    for (int i = 31; i >= 0; i--) {
        printf("%d", (a >> i) & 1);
    }
    printf("\n");

    return 0;
}
