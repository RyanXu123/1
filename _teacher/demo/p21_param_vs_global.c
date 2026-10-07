#include <stdio.h>

/* 写在所有函数外面 = 全局变量，每个函数都看得见（能跑，但不推荐） */
int global_num = 6;

/* 办法一：把值当参数递进去——函数拿到的是复印件，但它知道这个数是多少 */
int double_it(int x) {
    return x * 2;
}

/* 办法二：函数不带参数，直接去读外面的全局变量 */
/* 括号里那个 void 是"这个函数不收参数"的意思 */
int double_global(void) {
    return global_num * 2;
}

int main() {
    int num = 6;        /* main 里的局部盒子：别的函数看不见它 */

    printf("参数版 = %d\n", double_it(num));
    printf("全局版 = %d\n", double_global());

    return 0;
}
