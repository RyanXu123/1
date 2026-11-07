#include <stdio.h>
int sum_array(const int values[], int count)
{
   int sum=0;
   if(count==0){
    printf("空");
    return sum;
   }
   for(int i=0;i<count;i++){
    sum=sum+values[i];
   }
   return sum;

}
int main(void)
{
    int a[5] = {3, -1, 4, 2, 8};
    printf("%d\n", sum_array(a, 5));
    return 0;
}