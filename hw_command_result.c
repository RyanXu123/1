/* hw_command_result.c —— 第 38 讲作业
 *
 * 目标：
 *   - 让 doSet 交回 struct CommandResult；
 *   - 参数不是整数时，填好 badArgIndex；
 *   - 参数越界时，填好 badArgIndex / value / min / max；
 *   - 让 runOneCommand 把空行、未知命令、参数个数也变成带细节的结果。
 *
 * 只改 TODO 部分。main 的验收逻辑不要动。
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
    int volume;
};

struct CommandResult {
    enum CommandStatus status;
    int expectedArgs;
    int actualArgs;
    int badArgIndex;
    long value;
    long min;
    long max;
};

struct CommandResult makeResult(enum CommandStatus status)
{
    struct CommandResult result = {0};

    result.status = status;
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

/*
 * set 只收 1 个参数，范围是 0..100。
 * TODO：
 *   1. 不是完整整数：返回 CMD_BAD_NUMBER，并写 badArgIndex = 1；
 *   2. 超出 0..100：返回 CMD_OUT_OF_RANGE，并写 badArgIndex / value / min / max；
 *   3. 成功才写 st->volume，返回 CMD_OK。
 */
struct CommandResult doSet(char *words[], struct State *st)
{
    struct CommandResult result;
    long value;

    (void)words;
    (void)st;
    (void)value;
    result = makeResult(CMD_OK);
    return result; /* TODO */
}

struct CommandResult doShow(char *words[], struct State *st)
{
    (void)words;
    printf("volume=%d\n", st->volume);
    return makeResult(CMD_OK);
}

struct Cmd {
    char *name;
    int nArgs;
    struct CommandResult (*run)(char *words[], struct State *st);
};

struct Cmd table[] = {
    {"set",  1, doSet},
    {"show", 0, doShow}
};

int nCmd = 2;

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
 * TODO：
 *   n == 0：CMD_EMPTY；
 *   查不到命令：CMD_UNKNOWN；
 *   参数个数不对：CMD_BAD_ARG_COUNT，并填 expectedArgs / actualArgs；
 *   否则调用 table[idx].run，把整包结果交回去。
 */
struct CommandResult runOneCommand(char *words[], int n, struct State *st)
{
    struct CommandResult result;

    (void)words;
    (void)n;
    (void)st;
    result = makeResult(CMD_OK);
    return result; /* TODO */
}

void printCommandError(char *words[], struct CommandResult result)
{
    switch (result.status) {
    case CMD_OK:
        return;
    case CMD_EMPTY:
        printf("空行\n");
        return;
    case CMD_UNKNOWN:
        printf("未知命令：%s\n", words[0]);
        return;
    case CMD_BAD_ARG_COUNT:
        printf("%s 要 %d 个参数，收到 %d 个\n",
               words[0], result.expectedArgs, result.actualArgs);
        return;
    case CMD_BAD_NUMBER:
        printf("%s 的第 %d 个参数不是完整整数：%s\n",
               words[0], result.badArgIndex, words[result.badArgIndex]);
        return;
    case CMD_OUT_OF_RANGE:
        printf("%s 的第 %d 个参数超出范围：%ld 不在 %ld..%ld\n",
               words[0],
               result.badArgIndex,
               result.value,
               result.min,
               result.max);
        return;
    default:
        printf("未知状态\n");
        return;
    }
}

void runTest(char *words[], int n, struct State *st)
{
    struct CommandResult result;

    result = runOneCommand(words, n, st);
    printCommandError(words, result);
}

int main(void)
{
    struct State st = {7};
    char *ok[] = {"set", "42"};
    char *show[] = {"show"};
    char *badNumber[] = {"set", "4x"};
    char *badRange[] = {"set", "101"};
    char *badCount[] = {"set"};
    char *unknown[] = {"nope"};

    runTest(ok, 2, &st);
    runTest(show, 1, &st);
    runTest(badNumber, 2, &st);
    runTest(badRange, 2, &st);
    runTest(badCount, 1, &st);
    runTest(unknown, 1, &st);
    runTest(show, 1, &st);
    runTest(show, 0, &st);

    return 0;
}
