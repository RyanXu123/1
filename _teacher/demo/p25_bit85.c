#include <stdio.h>

int main() {
    int num = 85;

    printf("num = %d\n", num);
    printf("八位看：");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");

    printf("num >> 1      = %d   （砍掉最低位后剩下的整段）\n", num >> 1);
    printf("(num >> 1) & 1 = %d  （这才是第 1 位）\n", (num >> 1) & 1);
    printf("\n");

    for (int i = 0; i <= 7; i++) {
        printf("第 %d 位 = %d\n", i, (num >> i) & 1);
    }

    return 0;
}
