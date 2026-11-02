/* p73_return_status.c —— 第 36 讲：返回值、状态和退出码
 *
 * 输入一个 0 到 100 的亮度值，演示三个不同出口：
 *   1. readVolume 的返回值：告诉调用者成功还是哪种失败
 *   2. int *out：真正解析出来的数字
 *   3. main 的 return：交给操作系统的退出码
 *
 * 编译：
 *   gcc -Wall -Wextra p73_return_status.c -o p73_return_status
 *
 * 位置：
 *   cpp-demo\_teacher\demo\
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
 * 返回：这次读取是什么结果。
 * out ：只有 READ_OK 时才写入，成功时存解析到的数字。
 */
enum ReadStatus readVolume(const char *text, int *out)
{
    char *end;
    long value;

    if (text[0] == '\0') {
        return READ_EMPTY;
    }

    value = strtol(text, &end, 10);
    if (end == text || *end != '\0') {
        return READ_NOT_NUMBER;
    }

    if (value < 0 || value > 100) {
        return READ_OUT_OF_RANGE;
    }

    *out = (int)value;
    return READ_OK;
}

int main(void)
{
    char line[64];
    char *newline;
    enum ReadStatus status;
    int volume = -1;
    int exitCode;

    printf("请输入 0 到 100 的亮度：");
    if (fgets(line, sizeof line, stdin) == NULL) {
        printf("没有收到输入。\n");
        return 20;
    }

    newline = strchr(line, '\n');
    if (newline != NULL) {
        *newline = '\0';
    }

    status = readVolume(line, &volume);

    switch (status) {
    case READ_OK:
        printf("收到亮度：%d\n", volume);
        exitCode = 0;
        break;
    case READ_EMPTY:
        printf("错误：输入是空的。\n");
        exitCode = 10;
        break;
    case READ_NOT_NUMBER:
        printf("错误：不是完整的十进制整数。\n");
        exitCode = 11;
        break;
    case READ_OUT_OF_RANGE:
        printf("错误：亮度必须在 0 到 100 之间。\n");
        exitCode = 12;
        break;
    default:
        printf("错误：收到未知状态。\n");
        exitCode = 99;
        break;
    }

    return exitCode;
}
