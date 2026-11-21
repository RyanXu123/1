#include <stdio.h>
enum light {
    red,
    yellow,
    green
};
int main(void) {
    enum light current_light = red;
    for(int k=0;k<6;k++){
        switch (current_light)
        {
        case red:
                printf("now is red\n");
                for(int i=0;i<8;i++){
                    printf("time has gone %d\n",i);
                }
                current_light=yellow;
                break;
        case yellow:
             printf("now is yellow\n");
            
             for(int i=0;i<2;i++){
                printf("time has gone %d\n",i);
             }
             current_light=green;
             break;
        case green:
              printf("now is green");
              for(int i=0;i<4;i++){
                printf("time has gone %d \n",i);
              }   current_light=red;
              break;     
        default:
            break;
        }}
    }

