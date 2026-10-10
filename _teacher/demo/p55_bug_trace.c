/* p55_bug_trace.c --- 第 23 讲演示（同一个错版，加了三盏灯）
 * 和 p55_bug_demo.c 只有三处不同：把 sum / max / min 三个中间量打印出来。
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

    /* 三盏灯：循环跑完立刻把累积量摊出来看 */
    printf("[灯] sum = %d\n", sum);
    printf("[灯] max = %d  min = %d\n", max, min);

    avg = (sum - max - min) / 6;

    printf("[灯] avg = %.2f\n", avg);
    printf("去掉最大最小后的平均 = %.2f\n", avg);

    return 0;
}