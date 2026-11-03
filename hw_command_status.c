/* hw_command_status.c —— 第 37 讲作业
 *
 * 目标：
 *   - 补完 doSet，让动作函数用 enum CommandStatus 报告结果；
 *   - 补完 runOneCommand，让空行、未知命令、参数个数错误、执行结果
 *     都沿调用链交回 runMenu。
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

/*
 * set 只收 1 个参数，范围是 0..100。
 * TODO：
 *   1. 参数不是完整整数，返回 CMD_BAD_NUMBER；
 *   2. 参数超出 0..100，返回 CMD_OUT_OF_RANGE；
 *   3. 两种情况都通过后，写 st->volume，返回 CMD_OK。
 */
enum CommandStatus doSet(char *words[], struct State *st)
{
    long value;

    (void)words;
    (void)st;
    (void)value;
    return CMD_OK; /* TODO */
}

enum CommandStatus doShow(char *words[], struct State *st)
{
    (void)words;
    printf("volume=%d\n", st->volume);
    return CMD_OK;
}

struct Cmd {
    char *name;
    int nArgs;
    enum CommandStatus (*run)(char *words[], struct State *st);
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
 *   n == 0 时返回 CMD_EMPTY；
 *   查不到命令返回 CMD_UNKNOWN；
 *   参数个数不对返回 CMD_BAD_ARG_COUNT；
 *   否则调用 table[idx].run，并把它的返回值继续交回去。
 */
enum CommandStatus runOneCommand(char *words[], int n, struct State *st)
{
    (void)words;
    (void)n;
    (void)st;
    return CMD_OK; /* TODO */
}

void printCommandError(char *words[], int n, enum CommandStatus status)
{
    switch (status) {
    case CMD_OK:
        return;
    case CMD_EMPTY:
        printf("空行\n");
        return;
    case CMD_UNKNOWN:
        printf("未知命令：%s\n", words[0]);
        return;
    case CMD_BAD_ARG_COUNT:
        printf("%s 的参数个数不对，收到 %d 个\n", words[0], n - 1);
        return;
    case CMD_BAD_NUMBER:
        printf("%s 的参数不是完整整数\n", words[0]);
        return;
    case CMD_OUT_OF_RANGE:
        printf("%s 的参数超出范围\n", words[0]);
        return;
    default:
        printf("未知状态\n");
        return;
    }
}

void runTest(char *words[], int n, struct State *st)
{
    enum CommandStatus status;

    status = runOneCommand(words, n, st);
    printCommandError(words, n, status);
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
