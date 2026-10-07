#include <stdio.h>
struct godu
{char major[20];int class;char sno[20];char dorm[20];
};
int main(){
    struct godu s1;
    struct godu s2;
    printf("give your major,class,sno,dorm\n");
    scanf("%s %d %s %s",s1.major,&s1.class,s1.sno,s1.dorm);
    printf("give your major,class,sno,dorm\n");
    scanf("%s %d %s %s",s2.major,&s2.class,s2.sno,s2.dorm);
    struct godu *p = &s1;
    printf("student1: %s %d %s %s\n", p->major, p->class, p->sno, p->dorm);

    p = &s2;
    printf("student2: %s %d %s %s\n", p->major, p->class, p->sno, p->dorm);
}
    
