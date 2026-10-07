/* p30_fsm.c —— 状态机：一台三档风扇
 *
 * 规矩：低档 3 秒 -> 中档 2 秒 -> 高档 1 秒 -> 回低档（一轮 6 秒）
 * 输入 N（秒数），打印第 1 秒到第 N 秒、每一秒风扇在哪个档。
 *
 * 这里用同一件事的两种写法对着看：
 *   写法一  状态变量 + 倒计时 + switch（题面说的"用 switch 实现状态切换"就是这条）
 *   写法二  把秒数折进周期，再按区间判断（等价，另一条路）
 */

#include <stdio.h>

/* 用枚举给"三种档位"起名字。
   枚举值从 0 开始排队：LOW=0、MID=1、HIGH=2 */
enum FanSpeed { LOW, MID, HIGH };

/* 打印一个档位的名字：一个值，几条路 —— 正是 switch 的形状 */
void print_speed(enum FanSpeed s) {
    switch (s) {
        case LOW:
            printf("低档");
            break;
        case MID:
            printf("中档");
            break;
        case HIGH:
            printf("高档");
            break;
        default:
            printf("未知");
            break;
    }
}

int main() {
    int n;
    printf("输入秒数 N：");
    scanf("%d", &n);

    /* ===== 写法一：状态变量 + 倒计时 + switch ===== */
    printf("\n写法一：\n");
    enum FanSpeed state = LOW;   /* 现在是什么档 */
    int left = 3;                /* 当前这一档还剩几秒 */

    for (int t = 1; t <= n; t++) {
        printf("第 %d 秒：", t);
        print_speed(state);
        printf("\n");

        left = left - 1;         /* 这一秒用掉了 */
        if (left == 0) {         /* 用光了，切下一档，并给新档定好秒数 */
            switch (state) {
                case LOW:
                    state = MID;
                    left = 2;
                    break;
                case MID:
                    state = HIGH;
                    left = 1;
                    break;
                case HIGH:
                    state = LOW;
                    left = 3;
                    break;
                default:
                    break;
            }
        }
    }

    /* ===== 写法二：把秒数折进周期 ===== */
    printf("\n写法二：\n");
    for (int t = 1; t <= n; t++) {
        int pos = (t - 1) % 6;   /* 折进 0~5：0/1/2 低档、3/4 中档、5 高档 */
        enum FanSpeed s;

        if (pos < 3) {
            s = LOW;
        } else if (pos < 5) {
            s = MID;
        } else {
            s = HIGH;
        }

        printf("第 %d 秒：", t);
        print_speed(s);
        printf("\n");
    }

    return 0;
}
