#include<stdio.h>
int main(){
 int a[5]={100,91,78,2,3};
 int pos=0;
 int min=a[0];
 for(int i=0;i<5;i++){if(a[i]<min){pos=i;
 
  
  min=a[i];}}
  printf("%d xiabiaoshi%d\n",min,pos);

}