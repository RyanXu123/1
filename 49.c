#include <stdio.h>
#include <string.h>
void findnum(int *a){
    if (*a==NULL)
    {
        printf("null\n");
    }
    
    
    int y=a[0];
    int i=0;
    for( i=0;i<sizeof(*a),i++){
        if (a[i]>a[0])
        {
            y=a[i];
        }
    }if(a[i]<=0){
            printf("null");
        }else{
            printf("%d",y);
        }
}
int main(){
    char c[] = {9, 2, 3};
    findnum(&c); 
}