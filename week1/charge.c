#include <stdio.h>

int main(){
    int money;
    scanf("%d", &money);
    printf("500원 동전 : %d개\n", money/500);
    printf("100원 동전 : %d개\n", (money%500)/100);
    printf("50원 동전 : %d개\n", (money%100)/50);
    printf("10원 동전 : %d개\n", (money%50)/10);
    return 0;
}