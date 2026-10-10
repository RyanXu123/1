/* p57_strlib.c --- 第 24 讲主示例（一份走到底）
 *   ① 自己写的那三个函数 vs 库里现成的那三个（同一个活的两套做法，摆在一个程序里对答案）
 *   ② 长度数的是字节，不是字数
 *   ③ 比较：逐格比编号；返回值只认"负 / 0 / 正"
 *   ④ strncpy 有刹车但不补 '\0'；== 不能比字符串
 * 注意：这个文件会出两条编译警告（第 ④ 段两处），两条都是材料，不是手滑。
 */
#include <stdio.h>
#include <string.h>

/* ---------- 自己写的一套（第 09 讲那套零件拼的，跟库里干同一个活） ---------- */

int myLen(char s[])
{
    int n = 0;

    while (s[n] != '\0') {
        n = n + 1;
    }

    return n;
}

int myCmp(char a[], char b[])
{
    int i = 0;

    while (a[i] == b[i] && a[i] != '\0') {
        i = i + 1;
    }

    if (a[i] == b[i]) {
        return 0;          /* 两串同时到头，一模一样 */
    }
    if (a[i] > b[i]) {
        return 1;          /* a 这一格更大，a 排后面 */
    }

    return -1;
}

void myCopy(char dst[], char src[])
{
    int i = 0;

    while (src[i] != '\0') {
        dst[i] = src[i];
        i = i + 1;
    }
    dst[i] = '\0';          /* 别忘了把结尾的暗号也搬过去 */
}

/* ---------- 库里现成的一套（住 string.h，不用自己写） ---------- */

int main(void)
{
    char a[20] = "apple";
    char b[20] = "banana";
    char c[20] = "apple";
    char box[20];              /* ① 里试搬串用 */
    char raw[20] = "AAAAAAA";  /* ④ 里试 strncpy 的刹车用 */
    char zh[10] = "中";
    int len;

    /* 说明：上面那三个函数是「自己写的一套」，下面调用的是「库里现成的一套」，
     * 两套干的是同一个活。这个程序让两边各跑一遍，是为了对答案——
     * 不是"两套拼起来才算完整"：整个程序从 #include 到最后一行只有这一个 main，
     * 它本身就已经是完整能跑的了。 */

    /* ① 同一个活，两套做法各来一遍 */
    len = strlen(a);        /* 库里交回来的不是 int，先接进 int 变量 */
    printf("[1] 长度     手写 myLen = %d      库 strlen = %d\n", myLen(a), len);
    printf("[1] 比 a、b  手写 myCmp = %d      库 strcmp = %d\n", myCmp(a, b), strcmp(a, b));
    printf("[1] 比 a、c  手写 myCmp = %d      库 strcmp = %d\n", myCmp(a, c), strcmp(a, c));
    myCopy(box, a);
    printf("[1] 手写搬一次：box = %s\n", box);
    strcpy(box, b);
    printf("[1] 库搬一次：  box = %s\n", box);

    /* ② 长度数的是字节 */
    printf("[2] strlen(中) = %d   （汉字在 UTF-8 下占 3 格）\n", (int)strlen(zh));

    /* ③ 比较：只认正负，别背数字 */
    printf("[3] strcmp(ABC, AB)      = %d\n", strcmp("ABC", "AB"));
    printf("[3] strcmp(ABA, ABZ)     = %d\n", strcmp("ABA", "ABZ"));
    printf("[3] strcmp(Zebra, apple) = %d   （大写在小写前面，跟词典不一样）\n", strcmp("Zebra", "apple"));

    /* ④ 两条警告都在这段 */
    strncpy(raw, "hello", 3);
    printf("[4] strncpy(raw, hello, 3) 之后 raw = [%s]\n", raw);

    if (a == c) {
        printf("[4] ==     说：一样\n");
    } else {
        printf("[4] ==     说：不一样  <- 内容明明一模一样\n");
    }
    if (strcmp(a, c) == 0) {
        printf("[4] strcmp 说：一样  <- 这才是比内容\n");
    }

    /* ⑤ 拼三段：同一个 strcat 调两次 —— 想拼几段就调几次 */
    char greet[60] = "你好，";     /* 目标要按三段加起来开够：9 + 5 + 18 + 1 <= 60 */

    printf("[5] 第一段：%s\n", greet);
    strcat(greet, a);                  /* 拼上 a（"apple"） */
    printf("[5] 两段：  %s\n", greet);
    strcat(greet, "，欢迎回来！");      /* 再拼第三段 */
    printf("[5] 三段：  %s\n", greet);

    return 0;
}