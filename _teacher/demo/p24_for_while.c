#include <stdio.h>

int main() {
    /* 数着次数：三要素全在括号里，for 顺手 */
    printf("for:   ");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n");

    /* 同一件事用 while：起点在外面，变化在肚子里 */
    printf("while: ");
    int j = 1;
    while (j <= 5) {
        printf("%d ", j);
        j = j + 1;
    }
    printf("\n");

    /* while 的地盘：不知道要转几次，只知道什么时候停 */
    printf("13 一直除 2：");
    int n = 13;
    while (n > 0) {
        printf("%d ", n);
        n = n >> 1;
    }
    printf("\n");

    return 0;
}
