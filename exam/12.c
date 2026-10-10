#include <stdio.h>
#define N 8
int box[N];
int head=0;
int tail=0;
int count=0;
void buffer_write(int data){
    box[tail]=data;
    tail=(tail+1)%N;
    if(count==N){
        head=(head+1)%N;
    }else{
        count++;
    }
}
int buffer_read(void){
    if(count==0){
       return -1;
    }int data=box[head];
    head=(head+1)%N;
    count--;
    return data;
}
void buffer_print(void){
    printf("buffer:");
    for(int i=0;i<count;i++){
        printf("%d ",box[(head+i)%N]);
    }
    printf("\n");
}
int main(void){
      int n;

    printf("写几个 ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        buffer_write(x);
    }
    buffer_print();

    printf("读几个 ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("读走 %d\n", buffer_read());
    }
    buffer_print();

    printf("再写几个 ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        buffer_write(x);
    }
    buffer_print();
   
}
