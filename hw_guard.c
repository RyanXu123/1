/* hw_guard.c —— 第 31 讲《给菜单装上校验》作业
 *
 * 规矩：只准用学到第 31 讲为止的零件。
 *   已给：readNum（30 讲）、inRange（31 讲）——这两件当样板，别改。
 *   要你写：setCircle、setDelay、countOk 三个空函数。
 *
 * 编译：gcc -Wall hw_guard.c -o hw_guard
 * 跑：  .\hw_guard.exe
 *
 * 判分看两样：① 编译零警告；② 跑出来的输出跟每个函数头上的"该有的结果"对上。
 */
#include <stdio.h>
#include <stdlib.h>

/* ——— 已给的样板，别动 ——— */

int readNum(char s[], long *out)
{
    char *end;
    long v;

    v = strtol(s, &end, 10);
    if (end == s) {
        return 0;
    }
    if (*end != '\0') {
        return 0;
    }

    *out = v;
    return 1;
}

int inRange(long v, long lo, long hi)
{
    if (v < lo || v > hi) {
        return 0;
    }
    return 1;
}

/* ——— 作业一：圆的半径 ———
 * 规矩：半径必须 > 0，且 <= 1000（用 inRange 也能写，注意 lo 取什么）。
 * 交回：0 = 收下；1 = 不是整数；2 = 超出范围。
 * 收下时把值写进 *r（r 是 int 盒子，记得先查范围再收窄）。
 *
 * 该有的结果：setCircle("120", &r) → 0，r = 120
 *              setCircle("0",   &r) → 2
 *              setCircle("abc", &r) → 1
 */
int setCircle(char s[], int *r)
{}             /* TODO：三道门，自己写 */


/* ——— 作业二：延时 ———
 * 规矩：毫秒必须 >= 0，且 <= 3600000。
 * 交回：0 = 收下；1 = 不是整数；2 = 超出范围。
 * 收下时把值写进 *ms（盒子是 long，不用收窄）。
 *
 * 该有的结果：setDelay("500", &ms) → 0，ms = 500
 *              setDelay("-1",  &ms) → 2
 *              setDelay("2s",  &ms) → 1
 */
int setDelay(char s[], long *ms)
{
    return -1;              /* TODO */
}

/* ——— 作业三：数一数 ———
 * 给一排字符串（vals）和一排的长度（n），用你的 setCircle 逐个过一遍，
 * 交回"收下了几个"。被拒的不算。
 *
 * 该有的结果：{"120", "0", "abc", "999", "1001"} → 2
 *              （120 和 999 收下；0 超范围、abc 不是数、1001 超范围）
 */
int countOk(char *vals[], int n)
{
    return -1;              /* TODO：for + 计数器 + setCircle */
}

/* ——— 下面是验收用的 main，别改 ——— */
int main(void)
{
    char *vals[5] = {"120", "0", "abc", "999", "1001"};
    int r = -99;
    long ms = -99;
    int rc;
    int k;

    printf("作业一：\n");
    rc = setCircle("120", &r);             /* 分两步写：先调用，再打印 */
    printf("  setCircle(\"120\") → %d，r = %d\n", rc, r);
    printf("  setCircle(\"0\")   → %d\n", setCircle("0", &r));
    printf("  setCircle(\"abc\") → %d\n", setCircle("abc", &r));

    printf("作业二：\n");
    rc = setDelay("500", &ms);
    printf("  setDelay(\"500\") → %d，ms = %ld\n", rc, ms);
    printf("  setDelay(\"-1\")  → %d\n", setDelay("-1", &ms));
    printf("  setDelay(\"2s\")  → %d\n", setDelay("2s", &ms));

    printf("作业三：\n");
    printf("  收下了 %d 个（该是 2）\n", countOk(vals, 5));

    printf("\n（现在打印 -1 和 -99，就是因为三个函数还没写。）\n");
    printf("五个值：");
    for (k = 0; k < 5; k = k + 1) {
        printf(" %s", vals[k]);
    }
    printf("\n");

    return 0;
}
