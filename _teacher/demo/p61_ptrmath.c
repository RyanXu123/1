/* p61_ptrmath.c —— 补充示例：指针加一格、两个门牌号相减、判 NULL
 *
 * 这三个写法在第 25 讲里用到了，但从来没正式讲过，这里补上。
 * 依赖：第 10 讲（门牌号、声明 int *p）、第 02 讲（显式转换 (int)）。
 * 编译：gcc -Wall p61_ptrmath.c -o p61_ptrmath
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    char line[16] = "xyA12E";
    char *pHead;
    char *pTail;
    char *miss;
    int nums[4] = {10, 20, 30, 40};
    int *q = nums;

    pHead = strchr(line, 'A');
    pTail = strchr(pHead + 1, 'E');

    printf("这一行是「%s」\n\n", line);

    printf("pHead 从 line 数过去是第 %d 格（A 在第 2 格）\n", (int)(pHead - line));
    printf("pTail 从 line 数过去是第 %d 格（E 在第 5 格）\n", (int)(pTail - line));
    printf("pTail - pHead = %d 格（A 到 E 之间隔了 3 格）\n", (int)(pTail - pHead));
    printf("pTail - pHead - 1 = %d（中间那段，也就是密码长度）\n\n", (int)(pTail - pHead - 1));

    printf("(pHead + 1) - pHead = %d 格 —— 指针加 1，就是往后挪一格\n",
           (int)((pHead + 1) - pHead));
    printf("(q + 1) - q = %d 格 —— int 的指针也一样，还是挪一格（只是那一格宽 4 字节）\n\n",
           (int)((q + 1) - q));

    miss = strchr(line, 'Z');
    if (miss == NULL) {
        printf("找 'Z'：strchr 交回来的是 NULL —— 意思是「没有」，不能拿去取字\n");
    }

    return 0;
}