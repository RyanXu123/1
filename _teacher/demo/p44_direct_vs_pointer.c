/* 直接写名字 vs 用指针：打印出来的字一样，差别在"谁决定打哪个盒子" */
#include <stdio.h>

struct GDOU {
    char major[20];
    int  klass;
    char sno[20];
    char dorm[20];
};

int main(void) {
    struct GDOU student1 = {"机电", 1262, "2026123456", "东12-305"};
    struct GDOU student2 = {"电气", 1263, "2026654321", "西3-108"};

    /* A：名字写死在 printf 里，想打第二个就得再抄一行 */
    printf("A 直接写名字: %s %d %s\n", student1.major, student1.klass, student1.dorm);
    printf("A 直接写名字: %s %d %s\n", student2.major, student2.klass, student2.dorm);

    /* B：printf 只写一次，换门牌就换目标 */
    struct GDOU *p = &student1;
    printf("B 用指针:     %s %d %s\n", p->major, p->klass, p->dorm);
    p = &student2;
    printf("B 用指针:     %s %d %s\n", p->major, p->klass, p->dorm);

    return 0;
}
