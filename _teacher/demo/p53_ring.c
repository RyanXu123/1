#include <stdio.h>

/* ---------- 环形缓冲区（教学版，4 格） ----------
 * 4 格是为了让"绕圈"看得见。题十二要的是 8 格。
 */
#define N 4

/* 三个全局变量：写在所有函数外面，任何函数都看得见、都能改。
 * （第 07 讲说过"全局能不用就不用"——这里是非用不可：
 *   题十二的 buffer_read()、buffer_print() 不带参数，它们只能靠全局看到缓冲。)
 */
int box[N];      /* 存数据的那 4 格 */
int head = 0;    /* 读指针：下一个要读的位置 */
int tail = 0;    /* 写指针：下一个要写的位置 */
int count = 0;   /* 现在里面有几个数（用它才分得清"空"和"满"） */

/* 写一个数进去。这个教学版满了就不收，题十二要的是"覆盖最早那个"。 */
void rb_push(int data)
{
    if (count == N) {
        printf("  [push %d] 满了，先不收\n", data);
        return;
    }
    box[tail] = data;
    printf("  [push %d] 写进 box[%d]\n", data, tail);
    tail = (tail + 1) % N;      /* 绕圈：写到最后再 +1 就回到 0 */
    count++;
}

/* 读一个数出来，空的返回 -1。 */
int rb_pop(void)
{
    if (count == 0) {
        printf("  [pop] 空的，返回 -1\n");
        return -1;
    }
    int data = box[head];
    printf("  [pop] 从 box[%d] 取走 %d\n", head, data);
    head = (head + 1) % N;      /* 读指针也绕圈 */
    count--;
    return data;
}

/* 按"从旧到新"的顺序把里面的数打出来。
 * 注意：绕圈之后，数据在数组里不是从 0 号格顺着排的，
 *      所以要从 head 数起：第 i 个在 (head + i) % N 号格。
 */
void rb_show(void)
{
    printf("  [show] head=%d tail=%d count=%d -> ", head, tail, count);
    if (count == 0) {
        printf("(空)");
    }
    for (int i = 0; i < count; i++) {
        int idx = (head + i) % N;
        printf("%d ", box[idx]);
    }
    printf("\n");
}

int main(void)
{
    printf("=== 先写 1 2 3 ===\n");
    rb_push(1);
    rb_push(2);
    rb_push(3);
    rb_show();

    printf("=== 读两个 ===\n");
    rb_pop();
    rb_pop();
    rb_show();

    printf("=== 再写 4、5：看 tail 怎么绕回 0 号格 ===\n");
    rb_push(4);
    rb_push(5);
    rb_show();

    printf("=== 再写 6，这回满了 ===\n");
    rb_push(6);
    rb_show();

    printf("=== 满了还写 7 ===\n");
    rb_push(7);
    rb_show();

    printf("=== 剩下的全读干净 ===\n");
    while (count > 0) {
        rb_pop();
    }
    rb_pop();
    rb_show();

    return 0;
}