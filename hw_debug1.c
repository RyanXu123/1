/* hw_debug1.c --- 第 23 讲作业（这个文件是你的，改它就对了）
 * 题目：下面 8 个数，输出 1) 总和 2) 平均值（两位小数） 3) 有几个数比平均值大。
 * 这个程序能编译、能跑、能出数，但里面有三处错。
 * 拿笔先算一遍正确答案，再编译运行，对一下就知道错没错。
 */
#include <stdio.h>

int main(void)
{
    int data[8] = {12, 7, 25, 9, 30, 4, 18, 11};
    int n = 8;
    int i;
    double sum = 0;
    int count = 0;
    double avg;

    for (i = 0; i < n; i++) {
        sum = sum + data[i];
    }

    avg = sum / n;

    for (i = 0; i < n; i++) {
        if (avg < data[i]) {
            count = count + 1;
        }
    }

    printf("总和 = %.2f\n", sum);
    printf("平均 = %.2f\n", avg);
    printf("比平均大的个数 = %d\n", count);

    return 0;
}