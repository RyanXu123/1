#include <stdio.h>

/* ---------- 环形缓冲·追踪版（8 格） ----------
 * 完全照题十二那个例子走一遍，每一步都把：
 *   ① box 的物理内容（0~7 号格里现在各摆着谁，-1 表示这格还没写过）
 *   ② head / tail / count
 *   ③ 「从旧到新」读出来的顺序
 * 一起打出来。
 *
 * 用途只有一个：把"格子里的排列"和"读出来的顺序"这两件事分开看清楚。
 * 这一版是给主人看流程的，函数名和题面不一样；题十二那份还得自己敲。
 */
#define N 8

int box[N];      /* 8 个格子，主程序里先铺成 -1，表示"还没写过" */
int head = 0;    /* 读指针 */
int tail = 0;    /* 写指针 */
int count = 0;   /* 圈里有几个数 */

/* 打印当前状态，一行一条 */
void dump(void)
{
    printf("       box=[");
    for (int i = 0; i < N; i++) {
        printf("%d ", box[i]);
    }
    printf("] head=%d tail=%d count=%d  顺序=", head, tail, count);
    for (int i = 0; i < count; i++) {
        printf("%d ", box[(head + i) % N]);   /* 从 head 数第 i 个 */
    }
    printf("\n");
}

/* 写一个数：满了就把最老的那个挤掉 */
void put(int data)
{
    if (count == N) {
        printf("  写 %d：满了，最老的 %d（在 box[%d]）被挤掉\n", data, box[head], head);
        head = (head + 1) % N;   /* 让开最老那格 */
        count--;
    }
    printf("  写 %d -> 落进 box[%d]\n", data, tail);
    box[tail] = data;
    tail = (tail + 1) % N;       /* 写指针绕圈 */
    count++;
    dump();
}

/* 读一个数：空的返回 -1 */
int get(void)
{
    if (count == 0) {
        printf("  读：空的，返回 -1\n");
        dump();
        return -1;
    }
    int data = box[head];
    printf("  读 -> 取走 box[%d] 里的 %d\n", head, data);
    head = (head + 1) % N;       /* 读指针绕圈 */
    count--;
    dump();
    return data;
}

int main(void)
{
    for (int i = 0; i < N; i++) {
        box[i] = -1;
    }

    printf("=== ① 依次写 1 2 3 4 5 ===\n");
    for (int v = 1; v <= 5; v++) {
        put(v);
    }

    printf("=== ② 读 2 个 ===\n");
    get();
    get();

    printf("=== ③ 再写 6 7 8 9 10 11 ===\n");
    for (int v = 6; v <= 11; v++) {
        put(v);
    }

    return 0;
}