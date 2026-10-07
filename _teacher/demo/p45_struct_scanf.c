/* 题八的可选版本：信息从键盘读进来（题面并不要求，写死初始化也算对） */
#include <stdio.h>

struct GDOU {
    char major[20];
    int  klass;
    char sno[20];
    char dorm[20];
};

int main(void) {
    struct GDOU student1;
    struct GDOU student2;

    printf("请输入 student1：专业 班级 学号 宿舍\n");
    scanf("%s %d %s %s", student1.major, &student1.klass, student1.sno, student1.dorm);

    printf("请输入 student2：专业 班级 学号 宿舍\n");
    scanf("%s %d %s %s", student2.major, &student2.klass, student2.sno, student2.dorm);

    printf("student1: %s %d %s %s\n", student1.major, student1.klass, student1.sno, student1.dorm);
    printf("student2: %s %d %s %s\n", student2.major, student2.klass, student2.sno, student2.dorm);

    struct GDOU *p = &student1;
    printf("指针指 student1: %s %d %s %s\n", p->major, p->klass, p->sno, p->dorm);

    p = &student2;
    printf("指针指 student2: %s %d %s %s\n", p->major, p->klass, p->sno, p->dorm);

    return 0;
}
