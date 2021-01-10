#include <stdio.h>

int combination(int a, int b){
    if(a==b||b==0){
        return 1;
    }
    else if(a<b){
        return 0;
    }
    else{
        return combination(a-1,b-1)+combination(a-1,b);
    }
}

int main(){
    int n, r;
    scanf("%d %d", &n, &r);
    printf("%d\n", combination(n,r));
    return 0;
}