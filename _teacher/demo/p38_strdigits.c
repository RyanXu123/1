/* 第 18 讲 · 零件演示：数字字符 → 数字
 * 编译：gcc -Wall -Wextra p38_strdigits.c -o p38_strdigits.exe
 */
#include <stdio.h>

int main(void) {
    /* 1. char 里装的是编号 */
    printf("'0' 的编号 = %d\n", '0');
    printf("'7' 的编号 = %d\n", '7');
    printf("'9' 的编号 = %d\n", '9');

    /* 2. 减 '0' 换回数字 */
    printf("'0' - '0' = %d\n", '0' - '0');
    printf("'7' - '0' = %d\n", '7' - '0');
    printf("'9' - '0' = %d\n", '9' - '0');

    /* 3. 反面：少一对引号，等于没减 */
    printf("'7' - 0   = %d   <- 少了一对引号\n", '7' - 0);

    /* 4. 逐格扫描，哪些是数字字符 */
    char s[] = "ABC7613459*@!";
    printf("\n逐格扫描 %s\n", s);
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            printf("  s[%d] = '%c'  -> 是数字，值 = %d\n", i, s[i], s[i] - '0');
        } else {
            printf("  s[%d] = '%c'  -> 不是数字（编号 %d）\n", i, s[i], s[i]);
        }
    }

    /* 5. 挑进 box，并数个数（先不排序） */
    int box[100];
    int m = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            box[m] = s[i] - '0';
            m++;
        }
    }
    printf("\n挑出来 %d 个：", m);
    for (int i = 0; i < m; i++) {
        printf("%d", box[i]);
    }
    printf("\n（这个顺序是挑到的先后，还没排序）\n");

    return 0;
}
