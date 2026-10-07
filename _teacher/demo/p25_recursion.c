#include <stdio.h>

/* 递归版：把 1 到 n 全部加起来 */
int sum_rec(int n){
    printf("    进 sum(%d)\n", n);

    if (n == 1) {
        printf("    sum(1) 碰到基线，直接返回 1\n");
        return 1;
    }

    int r = n + sum_rec(n - 1);
    printf("    出 sum(%d) = %d\n", n, r);
    return r;
}

/* 循环版：同一件事，用 for 干 */
int sum_loop(int n){
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s = s + i;
    }
    return s;
}

/* 递归版：把 n 的每一位倒着打出来（0 不进入递归） */
void print_rev(int n){
    if (n == 0) {
        return;
    }
    printf("%d", n % 10);
    print_rev(n / 10);
}

int main(){
    printf("=== 递归版 sum(5) ===\n");
    int a = sum_rec(5);
    printf("最终结果 = %d\n\n", a);

    printf("=== 循环版 sum(5) ===\n");
    int b = sum_loop(5);
    printf("最终结果 = %d\n\n", b);

    printf("=== 递归版倒序打印 153 的每一位 ===\n");
    print_rev(153);
    printf("\n");

    return 0;
}
