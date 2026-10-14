#include <stdio.h>
int main(){
    int a[5]
    int max=a[0];
    int pos=0;
    for(int i=0;i<5;i++){
        if (a[i]>max) {
            max=a[i];
            pos=i;
        }
    }
    printf("%d %d\n",max,pos);
    return 0;
}
