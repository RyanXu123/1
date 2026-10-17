/* p68b_level_guard.c —— 第 31 讲纯净版：只有"三道门 + 先查再动"
 *
 * 跟 p68_cmdmenu_guard.c 比，这一份把菜单、fgets、strtok 全拿掉了，
 * 只留今天这一个活：把一串候选字符当成"亮度"过一遍，看它能不能进门。
 *
 *   门一：这串不是空的
 *   门二：整串都是整数（readNum，第 30 讲原样搬来的）
 *   门三：0 ~ 255（inRange，今天新长的）
 *
 * 三道门全过才写进 level；被拒的那几次，level 一个字节都不许动。
 *
 * 编译：gcc -Wall p68b_level_guard.c -o p68b_level_guard
 * 位置：cpp-demo\_teacher\demo\
 */
#include <stdio.h>
#include <stdlib.h>

/* 第 30 讲的，一行没改：整串都是整数才收，值顺着 out 写回去 */
int readNum(char s[], long *out)
{
    char *end;
    long v;

    v = strtol(s, &end, 10);
    if (end == s) {
        return 0;
    }
    if (*end != '\0') {
        return 0;
    }

    *out = v;
    return 1;
}

/* 今天新长的：在 [lo, hi] 里才给 1 */
int inRange(long v, long lo, long hi)
{
    if (v < lo || v > hi) {
        return 0;
    }
    return 1;
}

/* 三道门。交回 0 表示收下，1/2/3 表示卡在哪道门——函数只回答，打印交给调用者 */
int setLevel(char s[], int *level)
{
    long v;

    if (s[0] == '\0') {                 /* 门一：空的 */
        return 1;
    }
    if (!readNum(s, &v)) {              /* 门二：不是整数 */
        return 2;
    }
    if (!inRange(v, 0, 255)) {          /* 门三：超出范围 */
        return 3;
    }

    *level = (int)v;                    /* 三道门都过了，才动状态 */
    return 0;
}

int main(void)
{
    char *tries[7] = {"128", "300", "abc", "12abc", "-1", "0", "255"};
    int level = 0;
    int k;
    int r;

    for (k = 0; k < 7; k = k + 1) {
        r = setLevel(tries[k], &level);

        if (r == 0) {
            printf("[%s] 收下，亮度 %d\n", tries[k], level);
        } else if (r == 1) {
            printf("[%s] 拒：参数是空的\n", tries[k]);
        } else if (r == 2) {
            printf("[%s] 拒：不是整数\n", tries[k]);
        } else {
            printf("[%s] 拒：超出 0~255\n", tries[k]);
        }
    }

    printf("\n最后 level = %d（中间那四次被拒，一次都没碰它）\n", level);

    return 0;
}
