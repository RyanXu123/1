/* p75_command_result.c —— 第 38 讲：状态后面再带一包细节
 *
 * 第 37 讲只让命令回答“成功还是哪种失败”。
 * 这一讲把错误细节也装进 struct CommandResult：
 *   - status       ：哪一种结局
 *   - badArgIndex  ：第几个参数出错
 *   - value        ：出错的值
 *   - min / max    ：允许范围
 *   - expectedArgs / actualArgs：参数个数
 *
 * 编译：
 *   gcc -Wall -Wextra p75_command_result.c -o p75_command_result
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

/*
 * 状态说明是哪一类结局；
 * 后面的字段说明这一类结局具体发生在哪里。
 */
struct CommandResult {
    enum CommandStatus status;
    int expectedArgs;
    int actualArgs;
    int badArgIndex;
    long value;
    long min;
    long max;
};

/*
 * 先造一个字段齐全、没有脏值的结果。
 * 后面的错误字段只在对应状态才有意义。
 */
struct CommandResult makeResult(enum CommandStatus status)
{
    struct CommandResult result = {0};

    result.status = status;
    return result;
}

/* badArgIndex 从 1 开始数：第 1 个参数、第 2 个参数。 */
struct CommandResult makeBadNumber(int badArgIndex)
{
    struct CommandResult result = makeResult(CMD_BAD_NUMBER);

    result.badArgIndex = badArgIndex;
    return result;
}

struct CommandResult makeOutOfRange(
    int badArgIndex,
    long value,
    long min,
    long max
)
{
    struct CommandResult result = makeResult(CMD_OUT_OF_RANGE);

    result.badArgIndex = badArgIndex;
    result.value = value;
    result.min = min;
    result.max = max;
    return result;
}

int readNum(const char *s, long *out)
{
    char *end;
    long value;

    value = strtol(s, &end, 10);
    if (end == s || *end != '\0') {
        return 0;
    }

    *out = value;
    return 1;
}

int inRange(long value, long min, long max)
{
    if (value < min || value > max) {
        return 0;
    }
    return 1;
}

struct CommandResult doMove(char *words[], struct State *st)
{
    long dx;
    long dy;

    if (!readNum(words[1], &dx)) {
        return makeBadNumber(1);
    }
    if (!readNum(words[2], &dy)) {
        return makeBadNumber(2);
    }
    if (!inRange(dx, -10000, 10000)) {
        return makeOutOfRange(1, dx, -10000, 10000);
    }
    if (!inRange(dy, -10000, 10000)) {
        return makeOutOfRange(2, dy, -10000, 10000);
    }

    st->x = st->x + (int)dx;
    st->y = st->y + (int)dy;
    printf("挪了 (%ld, %ld)，现在的位置：(%d, %d)\n",
           dx, dy, st->x, st->y);
    return makeResult(CMD_OK);
}

struct CommandResult doDelay(char *words[], struct State *st)
{
    long ms;

    (void)st;
    if (!readNum(words[1], &ms)) {
        return makeBadNumber(1);
    }
    if (!inRange(ms, 0, 3600000)) {
        return makeOutOfRange(1, ms, 0, 3600000);
    }

    printf("等 %ld 毫秒。\n", ms);
    return makeResult(CMD_OK);
}

struct CommandResult doLed(char *words[], struct State *st)
{
    long level;

    (void)st;
    if (!readNum(words[1], &level)) {
        return makeBadNumber(1);
    }
    if (!inRange(level, 0, 255)) {
        return makeOutOfRange(1, level, 0, 255);
    }

    printf("亮度设成 %ld。\n", level);
    return makeResult(CMD_OK);
}

struct CommandResult doWhere(char *words[], struct State *st)
{
    (void)words;
    printf("现在的位置：(%d, %d)\n", st->x, st->y);
    return makeResult(CMD_OK);
}

struct CommandResult doHome(char *words[], struct State *st)
{
    (void)words;
    st->x = 0;
    st->y = 0;
    printf("回到原点了：(0, 0)\n");
    return makeResult(CMD_OK);
}

struct CommandResult doQuit(char *words[], struct State *st)
{
    (void)words;
    st->running = 0;
    printf("退出。\n");
    return makeResult(CMD_OK);
}

struct Cmd {
    char *name;
    int nArgs;
    struct CommandResult (*run)(char *words[], struct State *st);
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

struct CommandResult runOneCommand(char *words[], int n, struct State *st)
{
    int idx;
    struct CommandResult result;

    if (n == 0) {
        return makeResult(CMD_EMPTY);
    }

    idx = findCmd(words[0]);
    if (idx < 0) {
        return makeResult(CMD_UNKNOWN);
    }

    if (n - 1 != table[idx].nArgs) {
        result = makeResult(CMD_BAD_ARG_COUNT);
        result.expectedArgs = table[idx].nArgs;
        result.actualArgs = n - 1;
        return result;
    }

    return table[idx].run(words, st);
}

void printCommandError(
    char *words[],
    int n,
    struct CommandResult result
)
{
    (void)n;

    switch (result.status) {
    case CMD_OK:
        return;
    case CMD_EMPTY:
        printf("空行。\n");
        return;
    case CMD_UNKNOWN:
        printf("表里没有这条命令：%s\n", words[0]);
        return;
    case CMD_BAD_ARG_COUNT:
        printf("%s 要 %d 个参数，主人给了 %d 个。\n",
               words[0], result.expectedArgs, result.actualArgs);
        return;
    case CMD_BAD_NUMBER:
        printf("%s 的第 %d 个参数不是完整整数：%s\n",
               words[0], result.badArgIndex, words[result.badArgIndex]);
        return;
    case CMD_OUT_OF_RANGE:
        printf("%s 的第 %d 个参数超出范围：%ld 不在 %ld..%ld。\n",
               words[0],
               result.badArgIndex,
               result.value,
               result.min,
               result.max);
        return;
    default:
        printf("收到未知命令状态：%d\n", (int)result.status);
        return;
    }
}

void runMenu(struct State *st)
{
    char line[128];
    char *words[8];
    char *p;
    int n;
    struct CommandResult result;

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

        result = runOneCommand(words, n, st);
        printCommandError(words, n, result);
    }

    printf("菜单结束，最后位置：(%d, %d)\n", st->x, st->y);
}

int main(void)
{
    struct State st = {0, 0, 1};

    runMenu(&st);
    return 0;
}
