#include <stdio.h>

int main(){
    char word[100];
    scanf("%s", word);
    for(int i=0;i<100;i++){
        if(word[i] == '\0'){
            printf("%d",i);
            break;
        }
    }
    return 0;
}