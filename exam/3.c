#include<stdio.h>
int panduan(int n){
    int t=n;
    int sum=0;
 
    while(t!=0){     int d = t % 10;
        sum = sum + d*d*d;
        t = t / 10;
    }
    if (sum == n) { return 1;}
    else {return 0;
    }}
int main(){int n;
    printf("giveme1num");
    scanf("%d",&n); 
      int count=0;
 for(int i=1;i<=n;i++){
    if(panduan(i)==1){
        printf("%d ", i);
        count=1;
    }
    }if(count==0){
        printf("0");
 }
}




