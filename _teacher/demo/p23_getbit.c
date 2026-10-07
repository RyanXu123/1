#include <stdio.h>

/* 取 a 的第 N 位：0 是最右边那一位 */
int get_bit(int a, int N) {
    return (a >> N) & 1;
}

int main() {
    int a;
    int N;

    printf("giveme1num\n");
    scanf("%d", &a);
    printf("dijiwei?\n");
    scanf("%d", &N);

    int num = get_bit(a, N);        /* main 里调用自己写的小函数 */
    printf("%d 的第 %d 位是 %d\n", a, N, num);

    return 0;
}
