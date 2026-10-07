/* p47_float_avg.c —— 第 20 讲：小数、%.2f、数组里找最大最小
 *
 * 编译：gcc -Wall -Wextra -o p47.exe p47_float_avg.c
 * 运行：p47.exe
 *
 * 这一讲不写题十的答案，只把零件摆开：
 *   零件一  整数除法 vs 浮点除法
 *   零件二  数组求和
 *   零件三  找最大值 / 最小值的下标
 */

#include <stdio.h>

/* ================= 零件一：除法 ================= */

void demo_divide(void)
{
    int a = 15;
    int b = 10;

    int whole = a / b;        /* 两个整数相除：小数被砍掉 */
    double real = a / 10.0;   /* 有一边写成小数，结果才是小数 */

    printf("15 / 10     (two ints)  = %d\n", whole);
    printf("15 / 10.0   (one float) = %f\n", real);
    printf("15 / 10.0   2 decimals  = %.2f\n", real);
}

/* ================= 零件二：数组求和 ================= */

int sum_all(int a[], int n)
{
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        total = total + a[i];
    }

    return total;
}

/* ================= 零件三：找最大 / 最小的位置 =================
 *
 * 打法叫「打擂台」：
 *   先让第 0 个上擂台（下标 0），从第 1 个开始挨个挑战；
 *   谁比擂主大，就把擂主换掉。比完剩下的那个就是最大的。
 *   找最小，把大于号改成小于号就行。
 */

int index_of_max(int a[], int n)
{
    int champ = 0;             /* 擂主：先假定第 0 个最大 */

    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[champ])
        {
            champ = i;         /* 换擂主，记的是下标 */
        }
    }

    return champ;
}

int index_of_min(int a[], int n)
{
    int champ = 0;

    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[champ])
        {
            champ = i;
        }
    }

    return champ;
}

/* ================= main：把三个零件挨个跑一遍 ================= */

int main(void)
{
    int data[10] = {3, 5, 1, 8, 2, 9, 4, 6, 7, 5};   /* 题十那组采样值 */
    int n = 10;

    demo_divide();

    printf("\ndata =");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", data[i]);
    }
    printf("\n");

    printf("sum of all  = %d\n", sum_all(data, n));

    int imax = index_of_max(data, n);
    int imin = index_of_min(data, n);
    printf("max is data[%d] = %d\n", imax, data[imax]);
    printf("min is data[%d] = %d\n", imin, data[imin]);

    /* 题十要的是「去掉一个最大、一个最小之后的平均值」。
     * data 里那个 9 和那个 1，是 sum_all 里也一起加进去的。
     * 怎么把它俩扣掉？扣完剩 8 个数，除以几才能出小数？—— 这段留给主人自己写。 */

    return 0;
}
