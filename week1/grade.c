#include <stdio.h>

int main(){
    int score;
    printf("Score : ");
    scanf("%d", &score);
    if(score>=90){
        printf("Your grade is A.");
    }
    else if(score>=80){
        printf("Your grade is B.");
    }
    else{
        printf("Your grade is F.");
    }
    return 0;
}