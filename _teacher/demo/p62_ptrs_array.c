/* p62_ptrs_array.c —— 补充示例：一排装门牌号的格子（char *lines[6]）
 *
 * 依赖：第 05 讲（数组是一排带编号的格子）、第 09 讲（字符串＝以 '\0' 结尾的 char 数组）、
 *       第 10 讲（char *p 里装的是 char 的门牌号）。
 * 编译：gcc -Wall p62_ptrs_array.c -o p62_ptrs_array
 */
#include <stdio.h>

int main(void)
{
    char *lines[6] = {"A12345678E", "AabcE", "A12345678", "12345678", "A12345678X", "AE"};
    char one[6] = "A1234";
    int k;

    printf("char *lines[6]：一排 6 格，每格里装的是一个门牌号。\n\n");

    for (k = 0; k < 6; k = k + 1) {
        printf("lines[%d] 指向的那串字是「%s」，第一个字节是 '%c'\n",
               k, lines[k], lines[k][0]);
    }

    printf("\nlines[0][1] 是第 0 串的第 1 个字节：'%c'\n", lines[0][1]);

    printf("\n对照 char one[6]：一排 6 格，每格里装的是一个字节。\n");
    printf("one[0] 是 '%c'（只是一个字节，不是一整串）\n", one[0]);

    return 0;
}