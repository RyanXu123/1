/* p65_cmdmenu.c —— 第 28 讲：做一条能一直用的命令菜单
 *
 * 一条命令走四步：
 *   ① fgets 读一整行（第 27 讲）
 *   ② 去掉行尾那个换行（第 27 讲）
 *   ③ strtok 按空格切成词，门牌号收进 words（第 26 讲）
 *   ④ strcmp 认第一个词是哪个命令（第 24 讲）
 *
 * 命令：set 名字 [备注] / who / quit
 * 编译：gcc -Wall p65_cmdmenu.c -o p65_cmdmenu
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    char line[80];                 /* 键盘来的一整行 */
    char work[80];                 /* 副本：strtok 会改串，line 留着 */
    char *words[8];                /* 一排装门牌号的格子 */
    char name[20] = "(空)";        /* 登记下来的名字 */
    char *p;
    int n;
    int j;

    printf("输命令：set 名字 [备注] / who / quit\n");

    while (fgets(line, sizeof line, stdin) != NULL) {   /* 读一整行；读到输入尽头给 NULL */

        p = strchr(line, '\n');                         /* ② 找行尾那个换行 */
        if (p != NULL) {
            *p = '\0';                                  /* 把那一格改成结束符 */
        }

        strcpy(work, line);                             /* 切的是副本，原件 line 留着 */

        n = 0;                                          /* ③ 切成词，只收门牌号 */
        p = strtok(work, " ");
        while (p != NULL && n < 8) {
            words[n] = p;
            n = n + 1;
            p = strtok(NULL, " ");
        }

        printf("> 这一行切成 %d 个词：", n);
        for (j = 0; j < n; j = j + 1) {
            printf("[%s] ", words[j]);
        }
        printf("\n");

        if (n == 0) {                                   /* ④ 认命令：空行先挑出来 */
            printf("（空行，什么都没干）\n");
        } else if (strcmp(words[0], "quit") == 0) {
            printf("退出。\n");
            break;
        } else if (strcmp(words[0], "who") == 0) {
            printf("当前登记的名字：%s（%d 个字节）\n", name, (int)strlen(name));
        } else if (strcmp(words[0], "set") == 0) {
            if (n < 2) {
                printf("set 后面要跟名字。\n");
            } else if ((int)strlen(words[1]) > 8) {
                printf("名字太长：%d 个字节，超过 8 个，不收。\n", (int)strlen(words[1]));
            } else {
                strcpy(name, words[1]);
                printf("名字收下了：%s\n", name);
                if (n > 2) {
                    printf("备注也收下了：%s\n", words[2]);
                }
            }
        } else {
            printf("不认识这个命令：%s\n", words[0]);
        }
    }

    return 0;
}
