/* err_p57_no_header.c --- 第 24 讲实验：故意**不写** #include <string.h>
 * 看看编译器怎么骂。下面的报错原文就出自这个文件（gcc 16.1.0）。
 */
#include <stdio.h>

int main(void)
{
    char s[20] = "hello";

    printf("len = %d\n", (int)strlen(s));
    printf("cmp = %d\n", strcmp(s, "hello"));

    return 0;
}