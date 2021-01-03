#include <stdio.h>

int main(){
    double arr[5];
    for(int i=0;i<5;i++){
        scanf("%lf", arr+i);
    }
    double* parr=arr;

    for(int i=0;i<5;i++){
        *(parr+i)*=2;
    }
    double sum;
    for(int i=0;i<5;i++){
        sum+=*(parr+i);
        printf("%lf ", *(parr+i));
    }
    printf("\nsum : %lf\n", sum);
    return 0;
}