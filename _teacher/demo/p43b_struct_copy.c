/* *p = student2;（右边去掉 &）—— 这是合法的：把整个结构体复制过去 */
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
    printf("复制前 p 指着 student1: %s %d\n", p->major, p->klass);

    *p = student2;
    printf("复制后 p 还是 student1: %s %d\n", student1.major, student1.klass);
    printf("student2 一个字没动:  %s %d\n", student2.major, student2.klass);

    return 0;
}
