//Link bài code :https://leetcode.com/problems/apple-redistribution-into-boxes/description/?envType=problem-list-v2&envId=greedy

//Code C greedy :
#include<stdlib.h>
int compare(const void*a,const void*b){
    return *(int*)b-*(int*)a;
}
int minimumBoxes(int* apple, int appleSize, int* capacity, int capacitySize) {
    int total=0;
    qsort(capacity,capacitySize,sizeof(int),compare);
    for(int i=0;i<appleSize;i++){
        total+=apple[i];
    }
    int min_box=0;
    for(int i=0;i<capacitySize;i++){
        if(total>0) {
            total-=capacity[i];
            min_box++;
        }
    }
    return min_box;
}
