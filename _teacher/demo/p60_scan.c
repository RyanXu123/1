/* p60_scan.c —— 第 25 讲主示例：把一串字符拆开用
 *
 * 场景：柜子从串口收到一行 "A12345678E"——A 是包头、E 是包尾，中间那串才是密码。
 *       程序要干的活就是「从一整行里抠出中间那一段」。
 * 做法一 grabMine：自己一个字一个字往后走（循环 + 下标，全部是学过的零件）。
 * 做法二 grabStrchr：用 string.h 里的现成工具 strchr 找头尾，再搬一段。
 * 两套跑同一个输入，结果对答案。
 *
 * 编译：gcc -Wall p60_scan.c -o p60_scan
 */
#include <stdio.h>
#include <string.h>

/* ---------------- 做法一：自己走 ---------------- */
int grabMine(char line[], char out[], int outSize)
{
    int i = 0;
    int j = 0;

    while (line[i] != '\0' && line[i] != 'A') {  /* 先找包头 A */
        i = i + 1;
    }
    if (line[i] == '\0') {
        return -1;                               /* 整行走完了也没看见 A */
    }

    i = i + 1;                                   /* 跨过 A，站到密码的第一个字节上 */
    while (line[i] != '\0' && line[i] != 'E') {  /* A 之后、E 之前，都是密码 */
        if (j >= outSize - 1) {                  /* 盒子小，塞不下就认输 */
            return -1;
        }
        out[j] = line[i];
        j = j + 1;
        i = i + 1;
    }
    if (line[i] != 'E') {
        return -1;                               /* 走完了也没等到 E */
    }
    if (j == 0) {
        return -1;                               /* A 和 E 挨着，中间是空的 */
    }

    out[j] = '\0';                               /* 收尾：自己拼出来的串，\0 得自己补 */
    return j;                                    /* 顺便把长度带出去 */
}

/* ---------------- 做法二：用 strchr ---------------- */
int grabStrchr(char line[], char out[], int outSize)
{
    char *pHead;
    char *pTail;
    int len;

    pHead = strchr(line, 'A');                   /* 找第一个 A，找到给门牌号，没找到给 NULL */
    if (pHead == NULL) {
        return -1;
    }

    pTail = strchr(pHead + 1, 'E');              /* 从 A 的下一格开始找 E */
    if (pTail == NULL) {
        return -1;
    }

    len = (int)(pTail - pHead - 1);              /* 两个门牌号相减 = 中间隔着几格 */
    if (len <= 0) {
        return -1;                               /* AE 挨着 */
    }
    if (len >= outSize) {
        return -1;                               /* 盒子不够大 */
    }

    strncpy(out, pHead + 1, len);                /* 只搬 len 个字节，不补 \0 */
    out[len] = '\0';                             /* 所以这句必须自己写 */
    return len;
}

int main(void)
{
    /* 六行样张：正常 / 短密码 / A 和 E 挨着 / 没有包头 / 没有包尾 / 只有 A 和 E */
    char *lines[6] = {"A12345678E", "AabcE", "A12345678", "12345678", "A12345678X", "AE"};
    char box1[20];
    char box2[20];
    int k;

    printf("规矩：包头 A，包尾 E，中间那段就是密码。\n\n");

    for (k = 0; k < 6; k = k + 1) {
        int r1 = grabMine(lines[k], box1, 20);
        int r2 = grabStrchr(lines[k], box2, 20);

        printf("收到「%s」\n", lines[k]);

        printf("  自己走：");
        if (r1 < 0) {
            printf("这一行收不了（没包头 / 没包尾 / 中间是空的）\n");
        } else {
            printf("密码「%s」，%d 个字节\n", box1, r1);
        }

        printf("  strchr：");
        if (r2 < 0) {
            printf("这一行收不了\n");
        } else {
            printf("密码「%s」，%d 个字节\n", box2, r2);
        }

        if (r1 != r2) {
            printf("  ！！两套结果不一样，去查\n");
        }
        printf("\n");
    }

    return 0;
}
