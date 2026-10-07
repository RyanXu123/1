#include <stdio.h>

/* 1 << n 就是「第 n 位那个 1」——拿它当工具，直接对原数动手 */
int set_bit(int num, int n)    { return num | (1 << n); }
int clear_bit(int num, int n)  { return num & ~(1 << n); }
int toggle_bit(int num, int n) { return num ^ (1 << n); }
int get_bit(int num, int n)    { return (num >> n) & 1; }

int main() {
    int num = 0x55;      /* 85，二进制 01010101 */
    int n = 1;

    printf("num = %d，n = %d\n", num, n);
    printf("1 << n = %d（就是第 1 位那个 1）\n", 1 << n);
    printf("set_bit    = %d\n", set_bit(num, n));
    printf("clear_bit  = %d\n", clear_bit(num, n));
    printf("toggle_bit = %d\n", toggle_bit(num, n));
    printf("get_bit    = %d\n", get_bit(num, n));

    /* 移位派：把目标位挪到最右边，但左边那一串也跟着来了 */
    printf("num >> n   = %d ← 这不是「第 n 位」，这是从第 n 位往上的一整段\n", num >> n);

    return 0;
}
