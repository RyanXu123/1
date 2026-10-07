#include <stdio.h>
void solve(double x1,double y1,double x2,double y2, double *pa,double *pb)
{
    double a=(y2-y1)/(x2-x1);
    *pa=a;
    *pb=y1-a*x1;
}
int main(void){double x1,y1,x2,y2;
   printf("输入x1,y1,x2,y2:");
   scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
    double a=0.0, b=0.0;
    solve(x1,y1,x2,y2,&a,&b);
    printf("a=%.2f b=%.2f\n",a,b);
}