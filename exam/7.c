#include<stdio.h>
int main(){
    int n;
    printf("giveme1奇数");
    scanf("%d",&n);
    int mid=(n+1)/2;
    for(int i=1;i<=mid;i++){
        for(int j=1;j<=mid-i;j++){
            printf(" ");
        }
        for(int j=1;j<=2*i-1;j++){

            printf("*");
        }
        printf("\n");

    }
    for(int k=1;k<=mid-1;k++){
        for(int j=1;j<=k;j++){
        printf(" ");
    }for(int j=1;j<=n-2*k;j++){
        printf("*");}
        printf("\n");
    }
   
}
