#include<stdio.h>
int main(){int n;
    printf("give me 1shuzi\n");
    scanf("%d",&n);
    int s=n%10;
    int a=n/10;
    int sum=(s*10)+a;
    if(n==sum){
         printf("ok\n");}
         else{
            printf("buok\n");
         }
}
