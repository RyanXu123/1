/* p55_bug_demo.c --- 第 23 讲演示（错版）
 * 任务：8 个数去掉最大和最小，剩下的算平均（两位小数）。
 * 这个文件能编译、能跑、能出数，但结果是错的。
 */
#include <stdio.h>

int main(void)
{
    int data[8] = {3, 5, 1, 8, 2, 9, 4, 6};
    int n = 8;
    int i;
    int sum = 0;
    int max;
    int min;
    double avg;

    for (i = 0; i < n - 1; i++) {
        sum = sum + data[i];
    }

    max = data[0];
    for (i = 1; i < n; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }

    min = data[0];
    for (i = 1; i < n; i++) {
        if (data[i] > min) {
            min = data[i];
        }
    }

    avg = (sum - max - min) / 6;

    printf("去掉最大最小后的平均 = %.2f\n", avg);

    return 0;
}