/* err_strtok_literal.c —— 故意崩的对照（第 26 讲）
 *
 * 干什么：把**字符串常量**交给 strtok。strtok 会在分隔符那一格写 '\0'，
 *         而常量住在只读区，写它 = 踩保护区 → 编译不响、运行当场崩。
 * 编译：gcc -Wall err_strtok_literal.c -o err_strtok_literal
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *line = "set Ryan";        /* 这是常量，不是能改的数组 */
    char *p;

    p = strtok(line, " ");          /* 往里写 '\0' —— 就在这一句崩 */
    printf("%s\n", p);
    return 0;
}
