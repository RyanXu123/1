/* p59_str_use.c --- 第 24 讲：这四个工具在真程序里干的活
 * 一个能真用的迷你程序：输命令、程序认字判断。
 * 三条命令：set 名字 / who / quit
 * 认命令用 strcmp；查名字长度用 strlen；把名字存下来用 strcpy；拼一句问候用 strcat
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    char cmd[20];
    char name[20];
    char card[20] = "（空）";
    int count = 0;

    printf("输命令：set 名字 / who / quit\n");

    while (1) {
        printf("> ");
        scanf("%s", cmd);

        if (strcmp(cmd, "quit") == 0) {
            printf("退出，本次登记了 %d 次。\n", count);
            break;
        } else if (strcmp(cmd, "who") == 0) {
            printf("当前登记的名字：%s\n", card);
        } else if (strcmp(cmd, "set") == 0) {
            char hello[40] = "你好，";
            int len;

            scanf("%s", name);
            len = strlen(name);

            if (len > 8) {
                printf("名字太长：%d 个字节，超过 8 个，不收。\n", len);
            } else {
                strcpy(card, name);
                strcat(hello, name);
                printf("%s\n", hello);
                count = count + 1;
            }
        } else {
            printf("不认识这个命令：%s\n", cmd);
        }
    }

    return 0;
}