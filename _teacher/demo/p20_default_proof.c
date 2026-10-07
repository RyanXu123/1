#include <stdio.h>

int main() {
    int i = 9;      /* 9 谁都不等于，所以走 default */

    switch (i) {
        default:                    /* 兜底那支，本座故意写在中间 */
            printf("其他\n");
            /* 这里故意不写 break，看看会不会掉下去 */
        case 100:
            printf("掉到 case 100 里了\n");
            break;
    }

    return 0;
}
