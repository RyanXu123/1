/* p33_call.c —— 把"调用函数"这件事缩到最小
 *
 * 左边是定义（写在 main 上面），右边是调用（写在 main 里面）。
 * 看懂了这一份，`print_speed(state);` 就是同一个形状。
 */

#include <stdio.h>

/* ---------- 定义 ---------- */
void say(int n) {              /* void = 不用还东西；int n = 要接一个整数 */
    printf("收到 %d\n", n);
}

int main() {
    int x = 7;

    /* ---------- 调用 ---------- */
    say(x);                    /* 把 x 的值交进去 */
    say(42);                   /* 也可以直接交一个数 */
    say(x + 1);                /* 交一个算式：先算成 8，再交进去 */

    return 0;
}
