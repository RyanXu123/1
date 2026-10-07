/* p32b_fallthrough.c —— 不写 break 会怎样（穿透）
 *
 * i = 1，会从 case 1 那扇门进去，然后一路往下做，直到撞上 break 或者撞到尾巴。
 */

#include <stdio.h>

int main() {
    int i = 1;

    switch (i) {
        case 0:
            printf("零\n");
            break;
        case 1:
            printf("一\n");
        case 2:
            printf("二\n");
        default:
            printf("其他\n");
            break;
    }

    return 0;
}
