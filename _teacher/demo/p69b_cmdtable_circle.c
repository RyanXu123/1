/* p69b_cmdtable_circle.c —— 第 32 讲：加一条 circle，只动两处
 *
 * 第 31 讲里，三条命令各写一份"查个数 + 报错"，加到十条就要抄十份。
 * 这一讲把"名字 / 要几个参数"搬进一张表：
 *   表先查名字，再查个数 —— 检查只写一次
 *   表查过了，才按条号分派动作（switch）
 *
 * 编译：gcc -Wall p69_cmdtable.c -o p69_cmdtable
 * 位置：cpp-demo\_teacher\demo\
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 一行一条命令：名字 + 它要几个参数 */
struct Cmd {
    char *name;
    int nArgs;
};

/* 整张表。加命令只在这儿添一行 —— 这是这一讲的骨头 */
struct Cmd table[] = {
    {"move",  2},
    {"delay", 1},
    {"led",   1},
    {"circle", 1},          /* ← 加命令第一处：表里添一行 */
    {"where", 0},
     {"home",0},
    {"quit",  0}
   
};

/* 表里有几条。加一行表，这个数要跟着改 —— 第 05 讲 sizeof 的活，以后补 */
int nCmd = 7;

/* —— 第 30、31 讲原样搬来 —— */
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

int inRange(long v, long lo, long hi)
{
    if (v < lo || v > hi) {
        return 0;
    }
    return 1;
}

/* 按名字在表里找：找到交回第几条，找不到交回 -1 */
int findCmd(char *name)
{
    int i;

    for (i = 0; i < nCmd; i = i + 1) {
        if (strcmp(table[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main(void)
{
    char line[128];
    char *words[8];
    char *p;
    int n;
    int idx;
    int running = 1;
    int x = 0;
    int y = 0;
    long a;
    long b;

    printf("输命令：move dx dy / delay ms / led level / circle r / where / home / quit\n");
    printf("表里一共 %d 条命令。\n", nCmd);

    while (running && fgets(line, sizeof line, stdin) != NULL) {
        p = strchr(line, '\n');
        if (p != NULL) {
            *p = '\0';
        }

        n = 0;
        p = strtok(line, " ");
        while (p != NULL && n < 8) {
            words[n] = p;
            n = n + 1;
            p = strtok(NULL, " ");
        }

        if (n == 0) {
            printf("空行。\n");
        } else {
            idx = findCmd(words[0]);

            if (idx < 0) {
                /* 第一道关：名字在不在表里 */
                printf("表里没有这条命令：%s\n", words[0]);
            } else if (n - 1 != table[idx].nArgs) {
                /* 第二道关：个数对不对 —— 只写这一次，所有命令共用 */
                printf("%s 要 %d 个参数，主人给了 %d 个。\n",
                       table[idx].name, table[idx].nArgs, n - 1);
            } else {
                /* 两道关都过了，才轮到各自动作 */
                switch (idx) {
                case 0:                              /* move dx dy */
                    if (!readNum(words[1], &a) || !readNum(words[2], &b)) {
                        printf("move 的参数里有不是数字的。\n");
                        break;
                    }
                    if (!inRange(a, -10000, 10000) || !inRange(b, -10000, 10000)) {
                        printf("一次最多挪 10000，收到 (%ld, %ld)。\n", a, b);
                        break;
                    }
                    x = x + (int)a;
                    y = y + (int)b;
                    printf("挪了 (%ld, %ld)，现在的位置：(%d, %d)\n", a, b, x, y);
                    break;

                case 1:                              /* delay ms */
                    if (!readNum(words[1], &a)) {
                        printf("delay 的参数不是数字：%s\n", words[1]);
                        break;
                    }
                    if (!inRange(a, 0, 3600000)) {
                        printf("毫秒要在 0 到 3600000 之间，收到 %ld。\n", a);
                        break;
                    }
                    printf("等 %ld 毫秒。\n", a);
                    break;

                case 2:                              /* led level */
                    if (!readNum(words[1], &a)) {
                        printf("led 的参数不是数字：%s\n", words[1]);
                        break;
                    }
                    if (!inRange(a, 0, 255)) {
                        printf("亮度只有 0 到 255，收到 %ld。\n", a);
                        break;
                    }
                    printf("亮度设成 %ld。\n", a);
                    break;

                case 3:                              /* circle r —— 第二处：添一段动作 */
                    if (!readNum(words[1], &a)) {
                        printf("circle 的参数不是数字：%s\n", words[1]);
                        break;
                    }
                    if (!inRange(a, 1, 1000)) {
                        printf("半径要在 1 到 1000 之间，收到 %ld。\n", a);
                        break;
                    }
                    printf("画一个半径 %ld 的圆。\n", a);
                    break;

                case 4:                              /* where，原来的 case 3 */
                    printf("现在的位置：(%d, %d)\n", x, y);
                    break;
                case 5:
                x=0; y=0;
                break;     

                default:                             /* quit，表里只有这一条能走到这 */
                    printf("退出。\n");
                    running = 0;
                    break;
                }
            }
        }
    }

    return 0;
}
