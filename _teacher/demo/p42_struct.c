/* 第 19 讲 · 结构体：画表 → 开盒子 → 用 . 和 -> 读
 * 编译：gcc -Wall -Wextra p42_struct.c -o p42_struct.exe
 */
#include <stdio.h>

/* 一、先画表：这就是"自己造一个类型" */
struct GDOU {
    char major[20];   /* 专业 */
    int  klass;       /* 班级 */
    char sno[20];     /* 学号（会带前导零，所以用一排 char） */
    char dorm[20];    /* 宿舍 */
};                    /* 末尾这个分号不能漏 */

int main(void) {
    /* 二、拿这张表开两个盒子，顺手填好（顺序要和定义对上） */
    struct GDOU student1 = {"机电", 1262, "2026123456", "东12-305"};
    struct GDOU student2 = {"电气", 1263, "2026654321", "西3-108"};

    /* 三、变量用 "." 读成员 */
    printf("student1: %s %d %s %s\n",
           student1.major, student1.klass, student1.sno, student1.dorm);
    printf("student2: %s %d %s %s\n",
           student2.major, student2.klass, student2.sno, student2.dorm);

    /* 四、一个指针，先后指向两个变量 */
    struct GDOU *p = &student1;              /* 先拿 1 号的门牌 */
    printf("\n指针指 student1：%s %d %s\n", p->major, p->klass, p->dorm);
    printf("  同一个东西用 (*p). 写也对：%d\n", (*p).klass);

    p = &student2;                            /* 换个门牌号，就这么简单 */
    printf("指针改指 student2：%s %d %s\n", p->major, p->klass, p->dorm);

    return 0;
}
