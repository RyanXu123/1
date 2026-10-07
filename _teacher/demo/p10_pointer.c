#include <stdio.h>
#include <windows.h>

/* 交换两个整数：参数是门牌号，所以能改到外面 */
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* 把外面那个变量加一 */
void addOne(int *p) {
    *p = *p + 1;
}

int main(void) {
    SetConsoleOutputCP(65001);

    int x = 3;
    int y = 7;
    int *p = &x;

    printf("x 住在：%p\n", &x);
    printf("x 的值：%d\n", *p);

    int *p = &x;
    printf("顺着 p 找到：%d\n", *p);

    printf("交换前：x=%d y=%d\n", x, y);
    swap(&x, &y);
    printf("交换后：x=%d y=%d\n", x, y);

    addOne(&y);
    printf("addOne 之后 y=%d\n", y);

    return 0;
}
