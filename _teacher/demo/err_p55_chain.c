/* err_p55_chain.c --- 故意编不过（第 23 讲）
 * 真正的错只有一处：第 9 行结尾少一个分号。
 * 其余几条报错都是被它带崩的，改完第一处再编译，它们会自己消失。
 */
#include <stdio.h>

int main(void)
{
    int a = 3
    int b = 5;
    int c = 0;

    c = a + b;
    printf("c = %d\n", c);

    return 0;
}