/* 把 p = &student2; 改成 *p = &student2; —— 左边是结构体，右边是地址 */
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

    struct GDOU *p = &student1;
    printf("p->student1: %s %d\n", p->major, p->klass);

    *p = &student2;
    printf("p->student2: %s %d\n", p->major, p->klass);

    return 0;
}
