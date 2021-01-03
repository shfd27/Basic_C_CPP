#include <stdio.h>

int add(int a, int b){
    return a+b;
}

int sub(int a, int b){
    return a-b;
}

int mul(int a, int b){
    return a*b;
}

double div(int a, int b){
    return (double)a/b;
}

int mod(int a, int b){
    return a%b;
}

int main(){
    int x, y;
    scanf("%d %d", &x, &y);
    printf("sum : %d\n",add(x,y));
    printf("difference : %d\n",sub(x,y));
    printf("multiplication : %d\n",mul(x,y));
    printf("division : %lf\n",div(x,y));
    printf("remainder : %d",mod(x,y));
    return 0;
}