#include <stdio.h>

int main(){
    int num;
    scanf("%d", &num);
    for(int k=1; k<=num; k++){
        for(int i=num-k; i>=1; i--){
            printf(" ");
        }
        printf("*");
        for(int i=0; i<=k-2; i++){
            printf(" *");
        }
        printf("\n");
    }
    for(int k=num-1; k>=1; k--){
        for(int i=num-k; i>=1; i--){
            printf(" ");
        }
        printf("*");
        for(int i=0; i<=k-2; i++){
            printf(" *");
        }
        printf("\n");
    }
    return 0;
}