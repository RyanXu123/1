#include <stdio.h>
int split_boxes(int boxes, int group_size, int *groups, int *left){
    *groups=boxes/group_size;
    *left=boxes%group_size;

}
int main(){int boxes;
    int groups_size;
    int groups;
    int left;
    printf("groups\n");
    scanf("%d",&boxes);
    printf("size\n");
    scanf("%d",&groups_size);
    if(boxes==0||groups_size==0){
        return -1;
     if(boxes<groups_size){
        return 0;
    }
    
    }
    split_boxes( boxes,groups_size,&groups,&left               );
    printf("%d %d",groups,left);
}