#include<stdio.h>
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
int main(){
    char n[20];
    printf("zi fu chuan shi\n");
    scanf("%s",n);
    int count=0;
    int box[100];int o=0;
    for(int i=0;n[i]!='\0';i++){
        if(n[i]>='0'&&n[i]<='9'){
            count++;
            box[o]=n[i]-'0';
            o++;

        }
    }printf("%d\n",count);
    for(int k=0;k<o-1;k++){
    for(int j=0;j<o-1-k;j++){ 
    if (box[j] > box[j + 1]) {
                swap(&box[j], &box[j + 1]);   
            }

}
   
}for (int i = 0; i < o; i++) {
    printf("%d", box[i]);
}}



