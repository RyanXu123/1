/* p71_state_funcptr.c —— 第 34 讲：把状态收进一个盒子，一路传下去
 *
 * 第 33 讲把 pos、running 摆成了文件级变量，省事但埋雷：
 * 谁都能改，改坏了也查不出来。
 *
 * 这一讲把它们收进 struct State，命令函数多收一个"盒子门牌号"：
 *   void doMove(char *words[], struct State *st)
 * 表里那一栏的签名跟着改，调用点把 &st 递进去。
 *
 * 编译：gcc -Wall p71_state_funcptr.c -o p71_state_funcptr
 * 位置：cpp-demo\_teacher\demo\
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 程序的所有状态，住在一个盒子里 */
struct State {
    int x;
    int y;
    int running;
};

/* —— 第 30、31 讲原样搬来 —— */
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

/* 每条命令都多收一张门牌号：st 指向 main 里那个 State */
void doMove(char *words[], struct State *st)
{
    long a;
    long b;

    if (!readNum(words[1], &a) || !readNum(words[2], &b)) {
        printf("move 的参数里有不是数字的。\n");
        return;
    }
    if (!inRange(a, -10000, 10000) || !inRange(b, -10000, 10000)) {
        printf("一次最多挪 10000，收到 (%ld, %ld)。\n", a, b);
        return;
    }

    st->x = st->x + (int)a;
    st->y = st->y + (int)b;
    printf("挪了 (%ld, %ld)，现在的位置：(%d, %d)\n", a, b, st->x, st->y);
}

void doDelay(char *words[], struct State *st)
{
    long a;

    (void)st;                           /* 这条命令不用状态，明说一声 */
    if (!readNum(words[1], &a)) {
        printf("delay 的参数不是数字：%s\n", words[1]);
        return;
    }
    if (!inRange(a, 0, 3600000)) {
        printf("毫秒要在 0 到 3600000 之间，收到 %ld。\n", a);
        return;
    }
    printf("等 %ld 毫秒。\n", a);
}

void doLed(char *words[], struct State *st)
{
    long a;

    (void)st;
    if (!readNum(words[1], &a)) {
        printf("led 的参数不是数字：%s\n", words[1]);
        return;
    }
    if (!inRange(a, 0, 255)) {
        printf("亮度只有 0 到 255，收到 %ld。\n", a);
        return;
    }
    printf("亮度设成 %ld。\n", a);
}

void doCircle(char *words[], struct State *st)
{
    long a;

    (void)st;
    if (!readNum(words[1], &a)) {
        printf("circle 的参数不是数字：%s\n", words[1]);
        return;
    }
    if (!inRange(a, 1, 1000)) {
        printf("半径要在 1 到 1000 之间，收到 %ld。\n", a);
        return;
    }
    printf("画一个半径 %ld 的圆。\n", a);
}

void doWhere(char *words[], struct State *st)
{
    (void)words;
    printf("现在的位置：(%d, %d)\n", st->x, st->y);
}

void doHome(char *words[], struct State *st)
{
    (void)words;
    st->x = 0;
    st->y = 0;
    printf("回到原点了：(0, 0)\n");
}

void doQuit(char *words[], struct State *st)
{
    (void)words;
    printf("退出。\n");
    st->running = 0;
}

/* 表：名字、参数个数、该调哪个函数。签名多了 st 那一项，这一栏也得跟着改 */
struct Cmd {
    char *name;
    int nArgs;
    void (*run)(char *words[], struct State *st);
};

struct Cmd table[] = {
    {"move",   2, doMove},
    {"delay",  1, doDelay},
    {"led",    1, doLed},
    {"circle", 1, doCircle},
    {"where",  0, doWhere},
    {"home",   0, doHome},
    {"quit",   0, doQuit}
};

int nCmd = 7;

int findCmd(char *name)
{
    int i;

    for (i = 0; i < nCmd; i = i + 1) {
        if (strcmp(table[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main(void)
{
    struct State st = {0, 0, 1};        /* 状态只有一个地方开 */
    char line[128];
    char *words[8];
    char *p;
    int n;
    int idx;

    printf("输命令：move dx dy / delay ms / led level / circle r / where / home / quit\n");
    printf("表里一共 %d 条命令。\n", nCmd);

    while (st.running && fgets(line, sizeof line, stdin) != NULL) {
        p = strchr(line, '\n');
        if (p != NULL) {
            *p = '\0';
        }

        n = 0;
        p = strtok(line, " ");
        while (p != NULL && n < 8) {
            words[n] = p;
            n = n + 1;
            p = strtok(NULL, " ");
        }

        if (n == 0) {
            printf("空行。\n");
        } else {
            idx = findCmd(words[0]);

            if (idx < 0) {
                printf("表里没有这条命令：%s\n", words[0]);
            } else if (n - 1 != table[idx].nArgs) {
                printf("%s 要 %d 个参数，主人给了 %d 个。\n",
                       table[idx].name, table[idx].nArgs, n - 1);
            } else {
                table[idx].run(words, &st);     /* 把盒子门牌号一起递进去 */
            }
        }
    }

    return 0;
}
