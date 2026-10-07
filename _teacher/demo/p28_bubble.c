#include <stdio.h>

/* 把数组前 n 个元素顺着打出来 */
void print_arr(int a[], int n){
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(){
    int a[6] = {7, 3, 9, 2, 6, 1};
    int n = 6;

    printf("排之前：");
    print_arr(a, n);

    for (int i = 0; i < n - 1; i++) {
        printf("\n第 %d 轮开始：", i + 1);
        print_arr(a, n);

        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                printf("    换了 a[%d] 和 a[%d] -> ", j, j + 1);
                print_arr(a, n);
            }
        }
        printf("  这一轮把最大的顶到了位置 %d\n", n - 1 - i);
    }

    printf("\n排之后：");
    print_arr(a, n);

    return 0;
}
