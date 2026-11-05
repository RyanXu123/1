/* p75b_result_pack.c —— 第 38 讲补课：结构体返回一包结果
 *
 * 只看三件事：
 *   1. struct 把几个成员装成一个变量；
 *   2. 函数可以 return 整个 struct；
 *   3. makeResult 只是先把一包结果清零，再把 status 填好。
 *
 * 编译：
 *   gcc -Wall -Wextra p75b_result_pack.c -o p75b_result_pack
 */
#include <stdio.h>

enum CommandStatus {
    CMD_OK = 0,
    CMD_BAD_NUMBER = 1
};

struct CommandResult {
    enum CommandStatus status;
    int badArgIndex;
    int value;
};

struct CommandResult makeResult(enum CommandStatus status)
{
    struct CommandResult result;

    result.status = status;
    result.badArgIndex = 0;
    result.value = 0;
    return result;
}

struct CommandResult doQuit(int *running)
{
    struct CommandResult result;

    *running = 0;
    result = makeResult(CMD_OK);
    return result;
}

struct CommandResult doBadExample(void)
{
    struct CommandResult result;

    result = makeResult(CMD_BAD_NUMBER);
    result.badArgIndex = 2;
    result.value = 99;
    return result;
}

void printResult(struct CommandResult result)
{
    printf("status=%d badArgIndex=%d value=%d\n",
           (int)result.status,
           result.badArgIndex,
           result.value);
}

int main(void)
{
    int running = 1;
    struct CommandResult quitResult;
    struct CommandResult badResult;

    quitResult = doQuit(&running);
    badResult = doBadExample();

    printf("quitResult: ");
    printResult(quitResult);
    printf("badResult : ");
    printResult(badResult);
    printf("running=%d\n", running);

    return 0;
}
