/* p74_command_status.c —— 第 37 讲：让命令把结果交回菜单
 *
 * 这一讲只改一件东西：
 *   动作函数不再只打印完就 return，而是交回 enum CommandStatus。
 *
 * 调用链：
 *   main -> runMenu -> runOneCommand -> table[idx].run
 *
 * 状态沿原路返回：
 *   动作函数 -> runOneCommand -> runMenu
 *
 * 编译：
 *   gcc -Wall -Wextra p74_command_status.c -o p74_command_status
 *
 * 位置：
 *   cpp-demo\_teacher\demo\
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum CommandStatus {
    CMD_OK = 0,
    CMD_EMPTY = 1,
    CMD_UNKNOWN = 2,
    CMD_BAD_ARG_COUNT = 3,
    CMD_BAD_NUMBER = 4,
    CMD_OUT_OF_RANGE = 5
};

struct State {
    int x;
    int y;
    int running;
};

int readNum(const char *s, long *out)
{
    char *end;
    long v;

    v = strtol(s, &end, 10);
    if (end == s || *end != '\0') {
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

enum CommandStatus doMove(char *words[], struct State *st)
{
    long dx;
    long dy;

    if (!readNum(words[1], &dx) || !readNum(words[2], &dy)) {
        return CMD_BAD_NUMBER;
    }
    if (!inRange(dx, -10000, 10000) || !inRange(dy, -10000, 10000)) {
        return CMD_OUT_OF_RANGE;
    }

    st->x = st->x + (int)dx;
    st->y = st->y + (int)dy;
    printf("挪了 (%ld, %ld)，现在的位置：(%d, %d)\n",
           dx, dy, st->x, st->y);
    return CMD_OK;
}

enum CommandStatus doDelay(char *words[], struct State *st)
{
    long ms;

    (void)st;
    if (!readNum(words[1], &ms)) {
        return CMD_BAD_NUMBER;
    }
    if (!inRange(ms, 0, 3600000)) {
        return CMD_OUT_OF_RANGE;
    }

    printf("等 %ld 毫秒。\n", ms);
    return CMD_OK;
}

enum CommandStatus doLed(char *words[], struct State *st)
{
    long level;

    (void)st;
    if (!readNum(words[1], &level)) {
        return CMD_BAD_NUMBER;
    }
    if (!inRange(level, 0, 255)) {
        return CMD_OUT_OF_RANGE;
    }

    printf("亮度设成 %ld。\n", level);
    return CMD_OK;
}

enum CommandStatus doWhere(char *words[], struct State *st)
{
    (void)words;
    printf("现在的位置：(%d, %d)\n", st->x, st->y);
    return CMD_OK;
}

enum CommandStatus doHome(char *words[], struct State *st)
{
    (void)words;
    st->x = 0;
    st->y = 0;
    printf("回到原点了：(0, 0)\n");
    return CMD_OK;
}

enum CommandStatus doQuit(char *words[], struct State *st)
{
    (void)words;
    st->running = 0;
    printf("退出。\n");
    return CMD_OK;
}

struct Cmd {
    char *name;
    int nArgs;
    enum CommandStatus (*run)(char *words[], struct State *st);
};

struct Cmd table[] = {
    {"move",  2, doMove},
    {"delay", 1, doDelay},
    {"led",   1, doLed},
    {"where", 0, doWhere},
    {"home",  0, doHome},
    {"quit",  0, doQuit}
};

int nCmd = 6;

int findCmd(const char *name)
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
 * 这里不做打印。它只回答一条命令是什么结局，
 * 让更外层的 runMenu 决定怎么显示。
 */
enum CommandStatus runOneCommand(char *words[], int n, struct State *st)
{
    int idx;

    if (n == 0) {
        return CMD_EMPTY;
    }

    idx = findCmd(words[0]);
    if (idx < 0) {
        return CMD_UNKNOWN;
    }

    if (n - 1 != table[idx].nArgs) {
        return CMD_BAD_ARG_COUNT;
    }

    return table[idx].run(words, st);
}

void printCommandError(char *words[], int n, enum CommandStatus status)
{
    int idx;

    switch (status) {
    case CMD_OK:
        return;
    case CMD_EMPTY:
        printf("空行。\n");
        return;
    case CMD_UNKNOWN:
        printf("表里没有这条命令：%s\n", words[0]);
        return;
    case CMD_BAD_ARG_COUNT:
        idx = findCmd(words[0]);
        printf("%s 要 %d 个参数，主人给了 %d 个。\n",
               table[idx].name, table[idx].nArgs, n - 1);
        return;
    case CMD_BAD_NUMBER:
        printf("%s 的参数里有不是完整整数的项。\n", words[0]);
        return;
    case CMD_OUT_OF_RANGE:
        printf("%s 的参数超出允许范围。\n", words[0]);
        return;
    default:
        printf("收到未知命令状态：%d\n", (int)status);
        return;
    }
}

void runMenu(struct State *st)
{
    char line[128];
    char *words[8];
    char *p;
    int n;
    enum CommandStatus status;

    printf("输命令：move dx dy / delay ms / led level / where / home / quit\n");

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

        status = runOneCommand(words, n, st);
        printCommandError(words, n, status);
    }

    printf("菜单结束，最后位置：(%d, %d)\n", st->x, st->y);
}

int main(void)
{
    struct State st = {0, 0, 1};

    runMenu(&st);
    return 0;
}
