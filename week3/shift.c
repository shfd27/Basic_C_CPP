#include <stdio.h>
#include <string.h>

int palindrome(char* strx){
    //change strx to lowercase
    for(int i=0; i<strlen(strx); i++){
        if(strx[i]<=90){
            strx[i]+=32;
        }
    }
    //check palindrome
    int pal=1;
    for(int i=0;i<strlen(strx)/2;i++){
        if(strx[i]!=strx[strlen(strx)-i-1]){
            pal=0;
            break;
        }
    }
    return pal;
}

int main(){
    char str1[10];
    scanf("%s", str1);
    for(int i=0; i<strlen(str1); i++){
        if(str1[i]<=90){
            str1[i]+=32;
        }
    }
    str1[0]-=32;
    printf("%s\n", str1);
    printf("%s\n", palindrome(str1) ? "Palindrome." : "Not palindrome.");
    return 0;
}