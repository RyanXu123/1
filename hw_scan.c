/* hw_scan.c --- 第 25 讲作业（这个文件是你的）
 * 题目：自己造三个工具，从一整行里挑出东西来。
 *   findChar(s, c)            返回字符 c 在 s 里的下标；没有就返回 -1（用 strchr 写）
 *   grabPwd(line, out, size)  从 "A密码E" 里把密码抠进 out；成功返回长度，失败返回 -1
 *   trimPrint(line)           把 line 打印出来，但只打印到第一个空格前面，然后换行
 * 现在三个函数都是空架子：能编译、能跑，但下面每一行都是错的。
 * 先把该输出的数在纸上算出来，再逐个填。
 */
#include <stdio.h>
#include <string.h>

int findChar(char s[], char c)
{
    return -1;
}

int grabPwd(char line[], char out[], int outSize)
{
    return -1;
}

void trimPrint(char line[])
{
    printf("%s\n", line);
}

int main(void)
{
    char line1[40] = "set Ryan";
    char line2[40] = "A12345678E";
    char box[20] = "空着";

    printf("findChar(\"set Ryan\", ' ') = %d     （要 3）\n", findChar(line1, ' '));
    printf("findChar(\"set Ryan\", 'z') = %d     （要 -1）\n", findChar(line1, 'z'));

    printf("grabPwd 返回 = %d，box = %s   （要 8，box = 12345678）\n",
           grabPwd(line2, box, 20), box);

    printf("trimPrint：");
    trimPrint(line1);                       /* 要打印出 set */

    return 0;
}
