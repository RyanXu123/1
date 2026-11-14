#include <stdio.h>
#include <stdlib.h>
int findmax(int *a,int n){
    int max=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>max){
            max=a[i];
        }
    }return max;
}
int  compact_above(int *a, int n, int threshold){
    int w=0;
    for(int p=0;p<n;p++){
        if(a[p]>threshold){
            a[w]=a[p];
            w++;
        }
    }return w;
}
void reverse_array(int *a, int n){
    for(int i=0;i<n-1;i++){
        for(int o=0;o<n-1-i;o++){
            int t=a[o];a[o]=a[o+1];a[o+1]=t;
        }
    }
}

int main(){
    int n;
    int k;
    printf("jigeshu?");
    scanf("%d",&n);
    int *a=malloc(sizeof(int)*n);
     if (a == NULL) {
        return 1;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&k);
        a[i]=k;

    }
    for(int i=0;i<n;i++){
        printf("a[%d]=%d\n",i,a[i]);
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+a[i];
    }printf("%d\n",sum);
    printf("max is %d\n",findmax(a,n));
    int threshold=0;
    printf("threshold is ");
    scanf("%d",&threshold);
    int w = compact_above(a, n, threshold);
    for(int i=0;i<w;i++){
        printf("a[%d]=%d",i,a[i]);
    }
    printf("\n");
    reverse_array(a,w);
     for(int i=0;i<w;i++){
        printf("a[%d]=%d",i,a[i]);
    }

free(a);
    a = NULL;
}