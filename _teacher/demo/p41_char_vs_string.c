/* %c 配一格，%s 配一排 —— 别串台
 * 编译：gcc -Wall -Wextra p41_char_vs_string.c -o p41_char_vs_string.exe
 */
#include <stdio.h>

int main(void) {
    /* 一、只想读一个字符：%c 要门牌号 &c */
    char c;
    printf("输入一个字符：");
    scanf("%c", &c);                 /* %c 配 &c */
    printf("  %%c 印： [%c]\n", c);
    printf("  %%d 印： [%d]（那是它在表里的编号）\n\n", c);

    /* 二、想读一串：%s 要数组名，不要 & */
    char s[20];
    printf("输入一串字符：");
    scanf("%s", s);                  /* %s 配数组名 */
    printf("  %%s 印整排： [%s]\n", s);
    printf("  只想印第一格： %%c 印 [%c]\n\n", s[0]);

    /* 三、把 scanf 替主人补上的 \0 找出来 */
    int m = 0;
    while (s[m] != '\0') {
        m++;
    }
    printf("  那排一共 %d 格，第 %d 格放着 \\0 —— scanf(\"%%s\") 自动补的\n", m, m);

    return 0;
}
