/* hw_strlib.c --- 第 24 讲作业（这个文件是你的）
 * 题目：自己造三个工具，跟库里的 strlen / strcmp / strcpy 对着干。
 *   myLen(s)      返回这串有几个字节（不算结尾的 '\0'）
 *   myCmp(a, b)   a 比 b 大返回 1，小返回 -1，一模一样返回 0
 *   myCopy(d, s)  把 s 整串搬进 d（连结尾的 '\0' 一起搬），不用返回什么
 * 现在三个函数都只写了 return 0;，所以程序能编译、能跑，但下面每一行都是错的。
 * 先把该输出的数在纸上算出来，再逐个填。
 */
#include <stdio.h>

int myLen(char s[])
{
    int len=0;
   while (s[len] != '\0') {
        len = len + 1;
    }
    return len;
}

int myCmp(char a[], char b[])
{
    return 0;
}

void myCopy(char dst[], char src[])
{
}

int main(void)
{
    char a[20] = "apple";
    char b[20] = "banana";
    char c[20] = "apple";
    char box[20] = "空着";

    printf("len(a)     = %d\n", myLen(a));        /* 要 5 */
    printf("cmp(a, b)  = %d\n", myCmp(a, b));     /* 要 -1 */
    printf("cmp(a, c)  = %d\n", myCmp(a, c));     /* 要 0 */
    printf("cmp(b, a)  = %d\n", myCmp(b, a));     /* 要 1 */

    myCopy(box, b);
    printf("box        = %s\n", box);             /* 要 banana */

    return 0;
}