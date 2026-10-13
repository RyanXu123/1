/* p64_fgets.c —— 第 27 讲主示例：从键盘读一整行（连空格一起收）
 * 这一份只做这一件事。
 * 编译：gcc -Wall p64_fgets.c -o p64_fgets
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    char line[40];                    /* 40 格的盒子 */

    printf("输一行，带空格的也行：");
    fgets(line, sizeof line, stdin);  /* 三个参数：装哪儿、最多收几格、从哪儿读 */

    printf("收到的是 [%s]\n", line);  /* 看那个 ] 跑哪儿去了 */
    printf("这一串一共 %d 个字符\n", (int)strlen(line));
    return 0;
}
