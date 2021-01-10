#include <stdio.h>

typedef struct{
    char name[10];
    int task_score;
    int mid_score;
    int final_score;
} Unist;

void printScore(Unist* persons, int len){
    for(int i=0; i<len;i++){
        int total=persons[i].task_score + persons[i].mid_score + persons[i].final_score;
        printf("%s %c\n",persons[i].name, total>=90 ? 'A': (total>=70 ? 'B':'F'));
    }
}

int main(){
    Unist member[3];
    for(int i;i<3;i++){
        scanf("%s", member[i].name);
        scanf("%d", &member[i].task_score);
        scanf("%d", &member[i].mid_score);
        scanf("%d", &member[i].final_score);
    }
    printScore(member, 3);
    return 0;
}