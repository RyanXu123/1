/* hw_return_status.c —— 第 36 讲作业
 *
 * 目标：让函数同时交回“状态”和“数据”。
 * 只改 TODO 部分；main 的验收逻辑不要动。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum ReadStatus {
    READ_OK = 0,
    READ_EMPTY = 1,
    READ_NOT_NUMBER = 2,
    READ_OUT_OF_RANGE = 3
};

/*
 * 要求：
 * - 空串返回 READ_EMPTY；
 * - 有非数字字符或只有一部分是数字，返回 READ_NOT_NUMBER；
 * - 合法整数但不在 1..1000，返回 READ_OUT_OF_RANGE；
 * - 1..1000 之间才写 *out = 解析值，并返回 READ_OK。
 */
enum ReadStatus readPositive(const char *text, int *out)
{
    (void)text;
    (void)out;
    return READ_OK; /* TODO */
}

int main(void)
{
    const char *tests[] = {"", "abc", "12abc", "0", "1001", "1", "1000", "42"};
    int value;
    int i;
    enum ReadStatus status;

    for (i = 0; i < 8; i = i + 1) {
        value = -1;
        status = readPositive(tests[i], &value);
        printf("[%s] status=%d value=%d\n", tests[i], (int)status, value);
    }

    return 0;
}
