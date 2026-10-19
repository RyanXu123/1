/* p70_cmdtable_funcptr.c —— 第 33 讲：让表自己记住该调哪个函数
 *
 * 第 32 讲的表只记"名字 + 几个参数"，动作还得靠 switch 的条号分派，
 * 表的顺序一动，case 的数字全得跟着改。
 *
 * 这一讲在表里多开一栏：run，装"该调哪个函数"。
 * 加命令从此只动两处：表里添一行、写一个函数。条号再也不用管。
 *
 * 编译：gcc -Wall p70_cmdtable_funcptr.c -o p70_cmdtable_funcptr
 * 位置：cpp-demo\_teacher\demo\
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 位置。这一讲为了把重点压在函数指针上，先摆成文件级的盒子 */
struct Pos {
    int x;
    int y;
};

struct Pos pos = {0, 0};
int running = 1;

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

/* —— 每条命令一个函数，签名全一样：收 words，不交回东西 —— */
void doMove(char *words[])
{
    long a;
    long b;

    if (!readNum(words[1], &a) || !readNum(words[2], &b)) {
        printf("move 的参数里有不是数字的。\n");
        return;
    }
    if (!inRange(a, -10000, 10000) || !inRange(b, -10000, 10000)) {
        printf("一次最多挪 10000，收到 (%ld, %ld)。\n", a, b);
        return;
    }

    pos.x = pos.x + (int)a;
    pos.y = pos.y + (int)b;
    printf("挪了 (%ld, %ld)，现在的位置：(%d, %d)\n", a, b, pos.x, pos.y);
}

void doDelay(char *words[])
{
    long a;

    if (!readNum(words[1], &a)) {
        printf("delay 的参数不是数字：%s\n", words[1]);
        return;
    }
    if (!inRange(a, 0, 3600000)) {
        printf("毫秒要在 0 到 3600000 之间，收到 %ld。\n", a);
        return;
    }
    printf("等 %ld 毫秒。\n", a);
}

void doLed(char *words[])
{
    long a;

    if (!readNum(words[1], &a)) {
        printf("led 的参数不是数字：%s\n", words[1]);
        return;
    }
    if (!inRange(a, 0, 255)) {
        printf("亮度只有 0 到 255，收到 %ld。\n", a);
        return;
    }
    printf("亮度设成 %ld。\n", a);
}

void doCircle(char *words[])
{
    long a;

    if (!readNum(words[1], &a)) {
        printf("circle 的参数不是数字：%s\n", words[1]);
        return;
    }
    if (!inRange(a, 1, 1000)) {
        printf("半径要在 1 到 1000 之间，收到 %ld。\n", a);
        return;
    }
    printf("画一个半径 %ld 的圆。\n", a);
}

void doWhere(char *words[])
{
    (void)words;                        /* 它不用参数，明说一声，免得更告警 */
    printf("现在的位置：(%d, %d)\n", pos.x, pos.y);
}

void doHome(char *words[])
{
    (void)words;
    pos.x = 0;
    pos.y = 0;
    printf("回到原点了：(0, 0)\n");
}

void doQuit(char *words[])
{
    (void)words;
    printf("退出。\n");
    running = 0;
}

/* 表：名字、参数个数、该调哪个函数 */
struct Cmd {
    char *name;
    int nArgs;
    void (*run)(char *words[]);         /* 一栏装"函数门牌号" */
};

struct Cmd table[] = {
    {"move",   2, doMove},
    {"delay",  1, doDelay},
    {"led",    1, doLed},
    {"circle", 1, doCircle},
    {"where",  0, doWhere},
    {"home",   0, doHome},
    {"quit",   0, doQuit}
};

int nCmd = 7;                           /* 表里有几条 */

/* 按名字找条号，找不到给 -1 */
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
                printf("表里没有这条命令：%s\n", words[0]);
            } else if (n - 1 != table[idx].nArgs) {
                printf("%s 要 %d 个参数，主人给了 %d 个。\n",
                       table[idx].name, table[idx].nArgs, n - 1);
            } else {
                table[idx].run(words);  /* 表里那栏存的是函数门牌号，照着调 */
            }
        }
    }

    return 0;
}
