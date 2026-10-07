#include <stdio.h>

/* 函数声明：先告诉编译器"有这么个函数、长这样"，结尾是分号 */
int add(int a, int b);

int main() {
    int s = add(3, 4);      /* main 里调用它 */
    printf("s = %d\n", s);
    return 0;
}

/* 正式的定义写在 main 后面也行，因为上面已经声明过了 */
int add(int a, int b) {
    return a + b;
}
