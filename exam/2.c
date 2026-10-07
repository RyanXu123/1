#include<stdio.h>
#include <stdlib.h>   
#include <time.h>
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
int  main(){int n;
    srand(time(NULL));
    int r=rand()%900+100;
    printf("shuzishi%d\n",r);
    printf("xuehaoshi");
    scanf("%d",&n);
    int box[20];int o=0;
    while(r!=0){
        int d=r%10;
        box[o]=d;
        o++;
        r=r/10;
    }while(n!=0){
        int c=n%10;
        box[o]=c;
        o++;
        n=n/10;
    }for (int i = 0; i < o; i++) {
    printf("%d\n", box[i]);
}for(int k=0;k<o-1;k++){
    for(int j=0;j<o-1-k;j++){ 
    if (box[j] > box[j + 1]) {
                swap(&box[j], &box[j + 1]);   
            }

}
   
}for (int i = 0; i < o; i++) {
    printf("%d", box[i]);
}}