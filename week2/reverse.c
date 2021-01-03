#include <stdio.h>

int main(){
    int arr[5];
    for(int i=0;i<5;i++){
        scanf("%d", arr+i);
    }
    int* parr=arr;
    for(int i=0;i<5/2;i++){
        int cnt=*(parr+i);
        *(parr+i)=*(parr+4-i);
        *(parr+4-i)=cnt;
    }
    for(int i=0;i<5;i++){
        printf("%d ", *(parr+i));
    }
    return 0;
}