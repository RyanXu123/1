/* 第 18 讲 · 补白：char 装的到底是什么
 * 编译：gcc -Wall -Wextra p39_charnum.c -o p39_charnum.exe
 */
#include <stdio.h>

int main(void) {
    /* 一、char 盒子里的东西，用两种印法看 */
    char c = '7';
    printf("char c = '7'      : %%c 印出来是 [%c]     %%d 印出来是 [%d]\n", c, c);

    /* 二、char 盒子里放 65，会印成 A */
    char a = 65;
    printf("char a = 65       : %%c 印出来是 [%c]     %%d 印出来是 [%d]\n", a, a);

    /* 三、整数 7 和字符 '7' 是两回事 */
    printf("整数 7            : %%c 印出来是 [%c]（看不见，编号 7 是响铃） %%d 印出来是 [%d]\n", 7, 7);
    printf("字符 '7'          : %%c 印出来是 [%c]     %%d 印出来是 [%d]\n", '7', '7');

    /* 四、连号，所以能减 */
    printf("\n编号表：'0'=%d  '1'=%d  '2'=%d  ...  '9'=%d\n", '0', '1', '2', '9');
    printf("'7' - '0' = %d\n", '7' - '0');
    printf("'0' + 7   = %d  ->  %%c 印出来是 [%c]\n", '0' + 7, '0' + 7);
    printf("'7' - 0   = %d  <- 减的是整数 0，等于没减\n", '7' - 0);

    /* 五、%s 是一整排，%c 是一格 */
    char s[] = "7A";
    printf("\ns = \"7A\"          : %%s 印整排 = [%s]\n", s);
    printf("一格一格看        : s[0] 的 %%c = [%c]（编号 %d）  s[1] 的 %%c = [%c]（编号 %d）\n",
           s[0], s[0], s[1], s[1]);
    printf("所以 s[0] 是字符 '7'，不是数字 7。\n");

    return 0;
}
