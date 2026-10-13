/* p64b_strip_newline.c —— 把 fgets 尾巴上那个换行去掉
 * 这一份只做这一件事：读一行，去掉换行，再打出来。
 * 编译：gcc -Wall p64b_strip_newline.c -o p64b_strip_newline
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    char line[40];
    char *p;

    printf("输一行：");
    fgets(line, sizeof line, stdin);

    p = strchr(line, '\n');           /* 找那格换行符，找到给门牌号，没找到给 NULL（第 25 讲） */
    if (p != NULL) {
        *p = '\0';                    /* 顺着门牌号，把那一格改成结束符 */
    }

    printf("处理之后 [%s]\n", line);
    printf("现在一共 %d 个字符\n", (int)strlen(line));
    return 0;
}
