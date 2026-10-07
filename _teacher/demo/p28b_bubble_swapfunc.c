#include <stdio.h>

/* 把交换那三行封成函数：收两个门牌号，进去直接改外面 */
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void print_arr(int a[], int n){
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    
    
}

int main(){
    int a[4] = {5, 2, 9, 1};
    int n = 4;

    printf("排之前：");
    print_arr(a, n);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);   /* 递地址，不是递值 */
            }
        }
    }

    printf("排之后：");
    print_arr(a, n);

    return 0;
}
