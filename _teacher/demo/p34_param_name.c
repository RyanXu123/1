/* p34_param_name.c —— 参数名只是个名字
 *
 * 把 `enum FanSpeed s` 里的 s 改成 speed，整段照跑。
 * 名字随你起，但"声明"和"用"必须统一。
 */

#include <stdio.h>

enum FanSpeed { LOW, MID, HIGH };

void print_speed(enum FanSpeed speed) {   /* 声明：类型 + 名字 */
    switch (speed) {                      /* 用：同一个名字 */
        case LOW:
            printf("低档\n");
            break;
        case MID:
            printf("中档\n");
            break;
        case HIGH:
            printf("高档\n");
            break;
        default:
            printf("未知\n");
            break;
    }
}

int main() {
    enum FanSpeed state = MID;

    print_speed(state);    /* 交出去的是 state，函数里接到的是 speed */

    return 0;
}
