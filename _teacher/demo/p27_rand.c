#include <stdio.h>
#include <stdlib.h>   /* rand / srand 住在这儿 */
#include <time.h>     /* time 住在这儿 */

int main(){
    srand(time(NULL));          /* 播种，整个程序只做一次 */

    printf("三次裸的 rand()：\n");
    for (int i = 0; i < 3; i++) {
        printf("  rand() = %d\n", rand());
    }

    printf("\n三个三位数（100~999）：\n");
    for (int i = 0; i < 3; i++) {
        int r = rand() % 900 + 100;
        printf("  第 %d 个：%d\n", i + 1, r);
    }

    printf("\n掷六次骰子（1~6）：");
    for (int i = 0; i < 6; i++) {
        printf(" %d", rand() % 6 + 1);
    }
    printf("\n");

    return 0;
}
