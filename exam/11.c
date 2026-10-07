#include<stdio.h>
enum light{red,yellow,green};
void light_state(enum light s){
    switch(s){
        case red:
        printf("red\n");
        break;
        case yellow:
        printf("yellow\n");
        break;
        case green:
        printf("green\n");
        break;
    }
}
int main(){
    int n;
    printf("giveme1num\n");
    scanf("%d",&n);
    enum light state=red;
    int left=5;
    for(int i=1;i<=n;i++){
        light_state(state);
        left--;
        if(left==0){
          switch(state){
            case red:
            state=green;
            left=4;
            break;
            case green:
            state=yellow;
            left=2;
            break;
            case yellow:
            state=red;
            left=5;
          }
        }

    }


}
