/* 读入一串字符（考核题五的第一步）
 * 编译：gcc -Wall -Wextra p40_read_string.c -o p40_read_string.exe
 */
#include <stdio.h>

int main(void) {
    /* 一排盒子：装一串字。想装 n 个字，开 n+1 格（最后一格留给 \0） */
    char s[100];

    printf("输入一串字符：");
    scanf("%s", s);            /* 注意：s 前面不写 & ——它本身就是门牌号 */

    /* 整串印：%s 从第一格一路印到 \0 */
    printf("整串印出来： [%s]\n", s);

    /* 一格一格看：%c 只印一格 */
    printf("一格一格看： ");
    for (int i = 0; s[i] != '\0'; i++) {
        printf("[%c]", s[i]);
    }
    printf("\n");

    /* 第 09 讲数长度：数到 \0 之前为止 */
    int n = 0;
    while (s[n] != '\0') {
        n++;
    }
    printf("一共 %d 格（不含结尾的 \\0）\n", n);

    /* 对照：一格 char 长什么样（这里直接给值，不从键盘读） */
    char c = 'A';
    printf("一格 char：  %%c 印出来 [%c]，%%d 印出来 [%d]\n", c, c);

    return 0;
}
