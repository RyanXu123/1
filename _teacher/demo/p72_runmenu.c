/* p72_runmenu.c —— 第 35 讲：把菜单搬进函数，main 只开一个头
 *
 * 调用链：
 *   main -> runMenu -> runOneCommand -> doMove
 * State 只开一次，门牌号一路往下传；没有文件级状态变量。
 *
 * 编译：
 *   gcc -Wall p72_runmenu.c -o p72_runmenu
 * 位置：
 *   cpp-demo\_teacher\demo\
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct State {
    int x;
    int y;
    int running;
};

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

void doMove(char *words[], struct State *st)
{
    long dx;
    long dy;

    if (!readNum(words[1], &dx) || !readNum(words[2], &dy)) {
        printf("move 的参数里有不是数字的。\n");
        return;
    }
    if (!inRange(dx, -10000, 10000) || !inRange(dy, -10000, 10000)) {
        printf("一次最多挪 10000，收到 (%ld, %ld)。\n", dx, dy);
        return;
    }

    st->x = st->x + (int)dx;
    st->y = st->y + (int)dy;
    printf("挪了 (%ld, %ld)，现在的位置：(%d, %d)\n",
           dx, dy, st->x, st->y);
}

void doDelay(char *words[], struct State *st)
{
    long ms;

    (void)st;
    if (!readNum(words[1], &ms)) {
        printf("delay 的参数不是数字：%s\n", words[1]);
        return;
    }
    if (!inRange(ms, 0, 3600000)) {
        printf("毫秒要在 0 到 3600000 之间，收到 %ld。\n", ms);
        return;
    }
    printf("等 %ld 毫秒。\n", ms);
}

void doLed(char *words[], struct State *st)
{
    long level;

    (void)st;
    if (!readNum(words[1], &level)) {
        printf("led 的参数不是数字：%s\n", words[1]);
        return;
    }
    if (!inRange(level, 0, 255)) {
        printf("亮度只有 0 到 255，收到 %ld。\n", level);
        return;
    }
    printf("亮度设成 %ld。\n", level);
}

void doWhere(char *words[], struct State *st)
{
    (void)words;
    printf("现在的位置：(%d, %d)\n", st->x, st->y);
}

void doHome(char *words[], struct State *st)
{
    (void)words;
    st->x = 0;
    st->y = 0;
    printf("回到原点了：(0, 0)\n");
}

void doQuit(char *words[], struct State *st)
{
    (void)words;
    printf("退出。\n");
    st->running = 0;
}

struct Cmd {
    char *name;
    int nArgs;
    void (*run)(char *words[], struct State *st);
};

struct Cmd table[] = {
    {"move",   2, doMove},
    {"delay",  1, doDelay},
    {"led",    1, doLed},
    {"where",  0, doWhere},
    {"home",   0, doHome},
    {"quit",   0, doQuit}
};

int nCmd = 6;

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

/*
 * 第二层：只管"一条已经切好的命令"。
 * 它不读键盘，也不负责开 State。
 */
void runOneCommand(char *words[], int n, struct State *st)
{
    int idx;

    if (n == 0) {
        printf("空行。\n");
        return;
    }

    idx = findCmd(words[0]);
    if (idx < 0) {
        printf("表里没有这条命令：%s\n", words[0]);
        return;
    }

    if (n - 1 != table[idx].nArgs) {
        printf("%s 要 %d 个参数，主人给了 %d 个。\n",
               table[idx].name, table[idx].nArgs, n - 1);
        return;
    }

    table[idx].run(words, st);
}

/*
 * 第一层：只管"从读到退出的整段过程"。
 * line、words、p、n 都是这个函数自己的局部变量。
 */
void runMenu(struct State *st)
{
    char line[128];
    char *words[8];
    char *p;
    int n;

    printf("输命令：move dx dy / delay ms / led level / where / home / quit\n");
    printf("表里一共 %d 条命令。\n", nCmd);

    while (st->running && fgets(line, sizeof line, stdin) != NULL) {
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

        runOneCommand(words, n, st);
    }

    printf("菜单结束，最后位置：(%d, %d)\n", st->x, st->y);
}

int main(void)
{
    struct State st = {0, 0, 1};
    runMenu(&st);
    return 0;
}
