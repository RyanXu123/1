#include<stdio.h>
int sumall(int a[],int n){
    int total=0;
    for(int i=0;i<n;i++){
        total=total+a[i];
    }
    return total;
}
int max(int a[],int n){
    int champ=0;
    for(int i=1;i<n;i++){
        if(a[i]>a[champ]){
            champ=i;
        }
    }
    return a[champ];
}
int min(int a[],int n){
    int champ=0;
    for(int i=1;i<n;i++){
        if(a[i]<a[champ]){
            champ=i;
        }
    }
    return a[champ]; 
}
double pinjun(int a[],int n){
    int imax=max(a,n);
    int imin=min(a,n);
    int total=sumall(a,n)-imax-imin;
    return (double)total/(n-2);
}
int main(){
    int box[100];
    int n;
    printf("giveme n ge shu\n");
    scanf("%d",&n);
    printf("giveme %d numbers\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&box[i]);
    }
    double avg=pinjun(box,n);
    printf("pinjunshu %.2f\n",avg);
}