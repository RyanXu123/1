/* p67_strtol_learn.c —— 第 30 讲（strtol）示例：一个值是"交回来"的，另一个是"写进盒子里"的
 *
 * 前置（都讲过）：
 *   fgets 读一整行 + 去掉行尾换行        第 27 / 28 讲
 *   strtok 把一行切成词                  第 26 讲
 *   char *words[8] 一排门牌号            补充_指针数组、第 05 / 10 讲
 *   & 取地址、*p 顺着门牌号取值          第 10 / 11 讲
 *   atoi 把字符串翻成 int                第 29 讲
 *   strtol / long / %ld                  第 30 讲
 *
 * 位置：cpp-demo\_teacher\demo\（示例都放这儿，cpp-demo 根目录只留主人的作业）
 * 编译：gcc -Wall p67_strtol_learn.c -o p67_strtol_learn
 * 跑：  .\p67_strtol_learn.exe
 *       然后敲一行，比如：  42abc 0 abc -5 10 20
 *       空行退出。
 *
 * 它一件事一件事给你看：
 *   ① atoi 交回什么（只有一个出口，分不出 abc 和 0）
 *   ② strtol 交回什么（等号接住的那个数）—— 返回值只有一个
 *   ③ 盒子 end 里装了什么（这是第二个出口，靠"往你给的盒子里写"，不是靠 return）
 *   ④ 用 %ld 把它打出来长什么样
 *   ⑤ readNum 收不收这串
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 纯数字？是就给 1，并顺着 out 把值写进调用者的盒子 */
int readNum(char s[], long *out)
{
    char *end;
    long v;

    v = strtol(s, &end, 10);     /* v 接住"交回来"的那个数 */
    if (end == s) {              /* 盒子说：停在起点，一格都没走 */
        return 0;
    }
    if (*end != '\0') {          /* 盒子说：后面还剩东西 */
        return 0;
    }

    *out = v;
    return 1;
}

int main(void)
{
    char line[80];
    char work[80];
    char *words[8];
    char *p;
    char *end;
    long v;
    long got;
    int n;
    int k;

    printf("试一个串给我看（空行退出）：\n");

    while (fgets(line, sizeof line, stdin) != NULL) {
        p = strchr(line, '\n');
        if (p != NULL) {
            *p = '\0';
        }
        if (line[0] == '\0') {
            break;
        }

        strcpy(work, line);
        n = 0;
        p = strtok(work, " ");
        while (p != NULL && n < 8) {
            words[n] = p;
            n = n + 1;
            p = strtok(NULL, " ");
        }

        for (k = 0; k < n; k = k + 1) {
            v = strtol(words[k], &end, 10);      /* 等号接住的：只有这一个数 */

            printf("\n[%s]\n", words[k]);
            printf("  atoi   给的是 %d\n", atoi(words[k]));
            printf("  strtol 交回 %ld        ← 等号接住的就是这一个（返回值只有一个）\n", v);
            printf("  盒子 end 里：");
            if (end == words[k]) {
                printf("还停在起点（一个数字都没读到）\n");
            } else if (*end == '\0') {
                printf("走到串尾了（整串都是数字）\n");
            } else {
                printf("停在 '%c' 那一格，后面还剩 \"%s\"\n", *end, end);
            }
            printf("  用 %%ld 打一遍：%ld\n", v);
            printf("  占五格打一遍：%5ld\n", v);

            got = -1;
            if (readNum(words[k], &got)) {
                printf("  结论：收，值是 %ld\n", got);
            } else {
                printf("  结论：不收，这不是一个纯数字\n");
            }
        }

        printf("\n再试一个（空行退出）：\n");
    }

    printf("收工。\n");
    return 0;
}
