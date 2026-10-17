/* p68_cmdmenu_guard.c —— 第 31 讲：给菜单装上校验
 *
 * 接前面的：
 *   第 28 讲  读一行 → 去换行 → 切词 → 认命令（菜单四步）
 *   第 29 讲  atoi：只有一个出口，"abc" 和 "0" 分不出
 *   第 30 讲  strtol + readNum：两个出口才分得出
 *
 * 这一份只加一件事：**先把参数查干净，再动状态**。
 *   坐标 dx dy：任意整数（可以负）
 *   毫秒 ms   ：非负，且不超过一小时
 *   亮度 level：0 ~ 255
 *
 * 命令：move dx dy / delay ms / led level / where / quit
 *
 * 编译：gcc -Wall p68_cmdmenu_guard.c -o p68_cmdmenu_guard
 * 位置：cpp-demo\_teacher\demo\
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 第 30 讲那个：整串都是数字才收，收下的值顺着 out 写回调用者 */
int readNum(char s[], long *out)
{
    char *end;
    long v;

    v = strtol(s, &end, 10);
    if (end == s) {                 /* 一个数字都没读到 */
        return 0;
    }
    if (*end != '\0') {             /* 后面还剩东西 */
        return 0;
    }

    *out = v;
    return 1;
}

/* 值域检查：在 [lo, hi] 里就给 1。这一讲新长出来的一层 */
int inRange(long v, long lo, long hi)
{
    if (v < lo || v > hi) {
        return 0;
    }
    return 1;
}

int main(void)
{
    char line[80];
    char work[80];
    char *words[8];
    char *p;
    long dxl;
    long dyl;
    long ms;
    long lv;
    int n;
    int x = 0;
    int y = 0;

    printf("输命令：move dx dy / delay ms / led level / where / quit\n");

    while (fgets(line, sizeof line, stdin) != NULL) {

        p = strchr(line, '\n');
        if (p != NULL) {
            *p = '\0';
        }

        strcpy(work, line);
        n = 0;
        p = strtok(work, " ");
        while (p != NULL && n < 8) {
            words[n] = p;
            n = n + 1;
            p = strtok(NULL, " ");
        }

        if (n == 0) {
            printf("（空行，什么都没干）\n");
        } else if (strcmp(words[0], "quit") == 0) {
            printf("退出。\n");
            break;
        } else if (strcmp(words[0], "where") == 0) {
            printf("现在的位置：(%d, %d)\n", x, y);
        } else if (strcmp(words[0], "move") == 0) {
            if (n != 3) {
                printf("move 要两个参数，主人给了 %d 个。\n", n - 1);
            } else if (!readNum(words[1], &dxl)) {
                printf("第一个参数不是数字：%s\n", words[1]);
            } else if (!readNum(words[2], &dyl)) {
                printf("第二个参数不是数字：%s\n", words[2]);
            } else if (!inRange(dxl, -10000, 10000) || !inRange(dyl, -10000, 10000)) {
                printf("一次最多挪 10000，主人给的是 (%ld, %ld)。\n", dxl, dyl);
            } else {
                int dx = (int)dxl;      /* 查过范围才收窄，第 30 讲那条规矩 */
                int dy = (int)dyl;

                x = x + dx;             /* 两条都过了，才动状态 */
                y = y + dy;
                printf("挪了 (%d, %d)，现在的位置：(%d, %d)\n", dx, dy, x, y);
            }
        } else if (strcmp(words[0], "delay") == 0) {
            if (n != 2) {
                printf("delay 要一个参数，主人给了 %d 个。\n", n - 1);
            } else if (!readNum(words[1], &ms)) {
                printf("毫秒不是数字：%s\n", words[1]);
            } else if (!inRange(ms, 0, 3600000)) {
                printf("毫秒要在 0 到 3600000 之间，收到 %ld。\n", ms);
            } else {
                printf("等 %ld 毫秒。\n", ms);
            }
        } else if (strcmp(words[0], "led") == 0) {
            if (n != 2) {
                printf("led 要一个参数，主人给了 %d 个。\n", n - 1);
            } else if (!readNum(words[1], &lv)) {
                printf("亮度不是数字：%s\n", words[1]);
            } else if (!inRange(lv, 0, 255)) {
                printf("亮度只有 0 到 255，收到 %ld。\n", lv);
            } else {
                printf("亮度设成 %ld。\n", lv);
            }
        } else {
            printf("不认识这个命令：%s\n", words[0]);
        }
    }

    return 0;
}
