#include <stdio.h>

/* 第 08 讲学过：数组当参数传进去，要连个数一起传 */
void print_all(int a[], int n){
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);       /* 一位接一位，连成一串 */
    }
    printf("\n");
}

void print_spaced(int a[], int n){
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);      /* 空格隔开，调试时看得清 */
    }
    printf("\n");
}

int main(){
    int box[6] = {3, 2, 1, 4, 5, 6};
    int o = 6;

    printf("连着打：      ");
    for (int i = 0; i < o; i++) {
        printf("%d", box[i]);
    }
    printf("\n");

    printf("空格隔开：    ");
    for (int i = 0; i < o; i++) {
        printf("%d ", box[i]);
    }
    printf("\n");

    printf("每行一个：\n");
    for (int i = 0; i < o; i++) {
        printf("  box[%d] = %d\n", i, box[i]);
    }

    printf("函数版（连着）：");
    print_all(box, o);

    printf("函数版（空格）：");
    print_spaced(box, o);

    return 0;
}
