#include <stdio.h>
int set_bit(int num,int n){
 return num|(1<<n);}
int clear_bit(int num,int n){
 return num&~(1<<n);}
 int toggle_bit(int num,int n){
 return num^(1<<n);}
 int get_bit(int num, int n){
  return (num >> n) & 1;}
  int main(){int num;
    int n;
    printf("giveme1num\n");
    scanf("%d",&num);
    printf("weishushi?\n");
    scanf("%d",&n);
    printf("把第%d位置 1，返回结果:%d\n",n,set_bit(num, n));
    printf("把第 %d位清 0，返回结果:%d\n",n,clear_bit(num, n));
    printf("把第 %d 位取反，返回结果:%d\n",n,toggle_bit(num, n));
    printf("返回第 %d 位的值:%d\n",n,get_bit(num, n));

  }



