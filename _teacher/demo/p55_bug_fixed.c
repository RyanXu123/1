/* p55_bug_fixed.c --- 第 23 讲演示（对照版：三处改对）
 * 正确结果：4.67
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

    for (i = 0; i < n; i++) {
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
        if (data[i] < min) {
            min = data[i];
        }
    }

    avg = (sum - max - min) / 6.0;

    printf("去掉最大最小后的平均 = %.2f\n", avg);

    return 0;
}