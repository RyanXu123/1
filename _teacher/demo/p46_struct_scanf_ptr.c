/* scanf 直接写 student1.xxx vs 走指针 p->xxx：填的是同一个学生 */
#include <stdio.h>

struct GDOU {
    char major[20];
    int  klass;
    char sno[20];
    char dorm[20];
};

int main(void) {
    struct GDOU student1;
    struct GDOU *p = &student1;          /* 指针一开始就指着 student1 */

    printf("A 版：直接写 student1.xxx\n");
    scanf("%s %d %s %s", student1.major, &student1.klass, student1.sno, student1.dorm);
    printf("  student1: %s %d %s %s\n", student1.major, student1.klass, student1.sno, student1.dorm);
    printf("  用指针看同一个盒子: %s %d %s %s\n", p->major, p->klass, p->sno, p->dorm);

    printf("B 版：走指针 p->xxx\n");
    scanf("%s %d %s %s", p->major, &p->klass, p->sno, p->dorm);
    printf("  student1: %s %d %s %s\n", student1.major, student1.klass, student1.sno, student1.dorm);

    return 0;
}
