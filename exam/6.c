#include<stdio.h>
int main(){
 int a[100];
 int n;
 printf("giveme n num");
 scanf("%d",&n);
 for(int i=0;i<n;i++){
  scanf("%d",&a[i]);
 }
 int pos=0;
 int min=a[0];
 for(int i=0;i<n;i++){if(a[i]<min){pos=i;
 
  
  min=a[i];}}
  printf("%d xiabiaoshi%d\n",min,pos);

}