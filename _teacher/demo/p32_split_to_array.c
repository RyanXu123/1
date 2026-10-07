#include <stdio.h>

int main(){
    int id = 12345;

    /* ── 题三那套：拆出来就用掉（加进 sum） ── */
    int t = id;
    int sum = 0;
    while (t != 0) {
        int d = t % 10;      /* 拿末位 */
        sum = sum + d;       /* 立刻用掉 */
        t = t / 10;          /* 削掉末位 */
    }
    printf("题三那套：各位相加 = %d（数字用完就扔）\n\n", sum);

    /* ── 题二这套：拆出来的先存着，不动它 ── */
    int box[20];             /* 二十个空盒子 */
    int n = 0;               /* n = 下一个空位是第几格，也等于已经存了几位 */

    t = id;
    while (t != 0) {
        int d = t % 10;
        box[n] = d;          /* 塞进第 n 格 */
        printf("第 %d 圈：t 是 %d，末位拿到 %d，放进 box[%d]，n 变成 %d\n",
               n + 1, t, d, n, n + 1);
        n = n + 1;
        t = t / 10;
    }

    printf("\n存完：box 里是 ");
    for (int i = 0; i < n; i++) {
        printf("%d ", box[i]);
    }
    printf("（一共 %d 位）\n", n);

    return 0;
}
