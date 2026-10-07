#include <stdio.h>
int main(void){
    int x = 3;

    printf("x 的值：%d\n", x);
    printf("x 的门牌号：%p\n", (void *)&x);

    int *p = &x;
    printf("顺着 p 摸过去：%d\n", *p);

    *p = 99;
    printf("现在 x 是：%d\n", x);

    return 0;
}
