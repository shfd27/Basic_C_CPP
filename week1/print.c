#include <stdio.h>

int main(){
    int stu_num;
    char stu_name[10];
    scanf("%d %s", &stu_num, stu_name);
    printf("Hi. %s %d", stu_name, stu_num);
    return 0;
}