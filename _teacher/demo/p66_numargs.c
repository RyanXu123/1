/* p66_numargs.c —— 第 29 讲：参数是数字（move dx dy）
 *
 * 前面四步还是第 28 讲那套（fgets 读行 → 去换行 → strtok 切词 → strcmp 认命令），
 * 这一份只多一件事：把切出来的词交给 atoi，变成能算的数字。
 *
 * 命令：move dx dy / where / quit
 * 编译：gcc -Wall p66_numargs.c -o p66_numargs
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>            /* atoi 住在这儿（跟第 16 讲 rand 一个家门） */

int main(void)
{
    char line[80];
    char work[80];
    char *words[8];
    char *p;
    int n;
    int x = 0;                 /* 当前位置 */
    int y = 0;

    printf("输命令：move dx dy / where / quit\n");

    while (fgets(line, sizeof line, stdin) != NULL) {

        p = strchr(line, '\n');
        if (p != NULL) {
            *p = '\0';
        }

        strcpy(work, line);
        n = 0;
        p = strtok(work, " ");
        while (p != NULL && n < 8) {
            words[n] = p;
            n = n + 1;
            p = strtok(NULL, " ");
        }

        if (n == 0) {
            printf("（空行，什么都没干）\n");
        } else if (strcmp(words[0], "quit") == 0) {
            printf("退出。\n");
            break;
        } else if (strcmp(words[0], "where") == 0) {
            printf("现在的位置：(%d, %d)\n", x, y);
        } else if (strcmp(words[0], "move") == 0) {
            if (n < 3) {
                printf("move 后面要跟两个数。\n");
            } else {
                int dx = atoi(words[1]);      /* 字符串 → 数字：这一步就是这一讲的全部 */
                int dy = atoi(words[2]);

                x = x + dx;
                y = y + dy;
                printf("挪了 (%d, %d)，现在的位置：(%d, %d)\n", dx, dy, x, y);
            }
        } else {
            printf("不认识这个命令：%s\n", words[0]);
        }
    }

    return 0;
}
