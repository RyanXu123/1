#include <stdio.h>

/* 形状一：有参数、有返回值 */
int add(int a, int b) {
    return a + b;
}

/* 形状二：有参数、没返回值（void） */
void show(int n) {
    printf("值是 %d\n", n);
}

/* 形状三：没参数、没返回值 */
void hello() {
    printf("打招呼\n");
}

int main() {
    int s = add(3, 4);
    show(s);
    hello();
    return 0;
}
