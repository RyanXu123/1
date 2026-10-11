/* p63b_split_mine.c —— 第 26 讲的"看肚子里"一份：不用库，自己一格一格切
 *
 * 它是给主人看"strtok 到底干了什么"的：找到词的开头、把结尾那个空格改写成 '\0'。
 * 平时写程序用 p63_strtok.c 那份（库里现成的），这一份是拆开看内部用的。
 *
 * 编译：gcc -Wall p63b_split_mine.c -o p63b_split_mine
 */
#include <stdio.h>

int splitMine(char line[], char *words[], int maxWords)
{
    int n = 0;
    int i = 0;

    while (line[i] != '\0') {
        while (line[i] == ' ') {                    /* 跳过一串空格，站到词的开头 */
            i = i + 1;
        }
        if (line[i] == '\0') {                      /* 后面只剩空格了 */
            break;
        }
        if (n >= maxWords) {                        /* 盒子满了 */
            break;
        }

        words[n] = &line[i];                        /* 记住这个词从哪一格开始 */
        n = n + 1;

        while (line[i] != '\0' && line[i] != ' ') { /* 往后找这个词的尾巴 */
            i = i + 1;
        }
        if (line[i] == ' ') {
            line[i] = '\0';                         /* 把那个空格改写成结束符 */
            i = i + 1;                              /* 跨过去，下一圈找下一个词 */
        }
    }
    return n;
}

int main(void)
{
    char line[40] = "set Ryan";
    char *words[8];
    int n;
    int j;

    n = splitMine(line, words, 8);

    printf("切成 %d 个词：", n);
    for (j = 0; j < n; j = j + 1) {
        printf("[%s] ", words[j]);
    }
    printf("\n");

    printf("切完之后，原数组只剩第一段能直接打：%s\n", line);
    return 0;
}
