#include <stdio.h>
int digui(int n){
    if(n==1){
        return 1;
    }
    int num=n*digui(n-1);
    return num;
    
}
int main(){int n;
    printf("giveme1num\n");
    scanf("%d",&n);
    printf("numis%d",digui(n));

}