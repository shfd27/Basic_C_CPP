#include <stdio.h>
#include <string.h>

int main(){
    char str1[20];
    char str2[10];
    int check;
    scanf("%s %s", str1, str2);
    printf("str1 : %s\n", str1);
    printf("str2 : %s\n", str2);
    printf("length of str1 : %ld\n", strlen(str1));
    printf("length of str2 : %ld\n", strlen(str2));
    check = strcmp(str1,str2);
    printf("str1+str2 : %s\n", strcat(str1, str2));
    printf("%s\n", check ? "Not same." : "Same.");
    return 0;
}