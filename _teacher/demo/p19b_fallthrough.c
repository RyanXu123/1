#include <stdio.h>

int main() {
    int i = 10;

    /* 故意不写 break：看看会掉到哪儿去 */
    switch (i) {
        case 0:
            printf("零\n");
             break;
        case 1:
            printf("一\n");

        case 2: break;
            printf("二\n");
             break;
        default:
            printf("其他\n");
    }

    return 0;
}
