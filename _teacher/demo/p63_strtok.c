/* p63_strtok.c —— 第 26 讲主示例：把一行切成几个词
 *
 * 场景：柜子收到一行 "set Ryan"——按空格切成词，再用 strcmp 认第一个词是哪个命令。
 * 这一份只做这一件事。（想看"不看库、自己一格一格切"的写法，另开 p63b_split_mine.c，
 * 两份各跑各的，不摆在一起对比。）
 *
 * 编译：gcc -Wall p63_strtok.c -o p63_strtok
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    char line[40] = "set Ryan";     /* 从串口收来的那一行 */
    char work[40];                  /* 副本：strtok 会改串，原件留着 */
    char *words[8];                 /* 一排装门牌号的格子：每一格指着一个词 */
    int n = 0;                      /* 收进了几个词 */
    char *p;
    int j;

    strcpy(work, line);             /* 复制一份，切的是副本 */

    p = strtok(work, " ");          /* 第一次：把整行交进去 */
    while (p != NULL && n < 8) {
        words[n] = p;
        n = n + 1;
        p = strtok(NULL, " ");      /* 之后：给 NULL，接着上次的位置往下切 */
    }

    printf("收到「%s」\n", line);
    printf("  切成 %d 个词：", n);
    for (j = 0; j < n; j = j + 1) {
        printf("[%s] ", words[j]);
    }
    printf("\n");

    if (n > 0 && strcmp(words[0], "set") == 0) {      /* 认命令：拿第一个词跟"set"比 */
        printf("  命令认出来了：set\n");
        if (n > 1) {
            printf("  它带的参数是：%s\n", words[1]);
        }
    } else {
        printf("  这个命令我不认识\n");
    }

    printf("  原件还在：「%s」\n", line);              /* 被切的是副本，原件没动 */
    return 0;
}
