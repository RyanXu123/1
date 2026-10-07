/* 基准：已经声明过的指针，改指向 —— 正确 */
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

    p = &student2;
    printf("p->student2: %s %d\n", p->major, p->klass);

    return 0;
}
