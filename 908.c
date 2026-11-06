#include <stdio.h>
#include <string.h>
void jie(char *a,char *b){
    strcat(a, b);
}
int main(){
    char c[100]="19288";
    char o[29]="9178";
    jie(c,o);
    printf("%s",c);
    return 0;
}//为什么&c &o会报错  为什么printf(char c)报错 