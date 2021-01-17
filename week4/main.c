#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WINDOWS
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x)*1000)
#endif

int turn=0;
const int cell=3;

int checkArr(int arr[][cell]){
    for(int i=0; i<cell; i++){
        if (arr[i][0]!=0 && arr[i][0]==arr[i][1] && arr[i][1]==arr[i][2]){
            return 1;
        }
    }
    for(int i=0; i<cell; i++){
        if (arr[0][i]!=0 && arr[0][i]==arr[1][i] && arr[1][i]==arr[2][i]){
            return 1;
        }
    }
    if (arr[0][0]!=0 && arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2]){
        return 1;
    }
    if (arr[0][2]!=0 && arr[0][2]==arr[1][1] && arr[1][1]==arr[2][0]){
        return 1;
    }
    for(int i=0; i<cell; i++){
        for(int j=0; j<cell; j++){
            if(arr[i][j]==0){
                return 0;
            }
        }
    }
    printf("finish");
    return 2;
}

void plotArr(int arr[][cell]){
    for(int i=0; i<cell; i++){
        for(int j=0; j<cell; j++){
            printf("%c ", arr[i][j]==0? '-':arr[i][j]==1? 'O':'X');
        }
        printf("\n");
    }

}

void putArr(int arr[][cell]){
    int xpos;
    int ypos;
    scanf("%d %d", &xpos, &ypos);
    if(arr[xpos][ypos]==0){
        arr[xpos][ypos]=1;
    }
    else{
        printf("yout can't put there!\n");
        putArr(arr);
    }
    turn=1;
}

void putArrAI(int arr[][cell]){
    Sleep(1000);
    int xpos;
    int ypos;
    srand(time(NULL));
    xpos=rand()%cell;
    ypos=rand()%cell;
    if(arr[xpos][ypos]==0){
        arr[xpos][ypos]=-1;
    }
    else{
        printf("thinking\n");
        putArrAI(arr);
    }
    turn=0;
}

void increaseround(){
    static int round=0;
    round++;
    printf("round : %d\n",round);
}

float win_check(int check, int turn, int** pscore){
    static int player_win=0;
    static int AI_win=0;
    static int tie=0;
    if(check==1){
        if(turn==1){
            player_win+=1;
            **pscore+=1;
        }
        else{
            AI_win+=1;
            *pscore[2]+=1;
        }
    }
    else if(check==2){
        tie+=1;
        *pscore[1]+=1;
    }
    float percentage=(float)player_win/(player_win+tie+AI_win);
    printf("win : %d tie : %d lose : %d\n", player_win, tie, AI_win);
    printf("winning percent : %.2f\n",percentage);
    return percentage;
}

typedef struct{
    const char* name;
    int win;
    int tie;
    int lose;
} Person;


int main(int argc, char* argv[]){
    if(argc==1){
        printf("This program needs name arguments.\n");
        printf("Please input names after call this program.\n");
        printf("<ex> (program) Alex Bob Charlie\n");
        return 0;
    }
    Person* pm = (Person*)malloc((argc-1) * sizeof(Person));

    for (int i=0; i<argc-1; i++){
        pm[i].name=argv[i+1];
        pm[i].win=0;
        pm[i].tie=0;
        pm[i].lose=0;
    }

    for(int i=0; i<argc-1; i++){
        char y[]="yes";
        char ans[5];
        strcpy(ans,y);
        while(!strcmp(ans,"yes")){
            printf("%s's turn\n",pm[i].name);
            int arr[3][3]={
                {0,0,0},
                {0,0,0},
                {0,0,0}
            };
            increaseround();
            while(!checkArr(arr)){
                if(turn==0){
                    putArr(arr);
                    plotArr(arr);
                    checkArr(arr);
                }
                else{
                putArrAI(arr);
                plotArr(arr);
                checkArr(arr);
                }
            }
            int* iscore[]={&pm[i].win, &pm[i].tie, &pm[i].lose};
            win_check(checkArr(arr), turn, iscore);
            printf("%d %d %d\n",pm[i].win,pm[i].tie,pm[i].lose);
            printf("want to do more?");
            scanf("%s",ans);
            while(strcmp(ans,"yes") && strcmp(ans,"no")){
                printf("want to do more?");
                scanf("%s",ans);
            }
        }
    }

    for(int i=0; i<argc-1; i++){
        printf("%s wins %d,ties %d, loses %d.\n",pm[i].name,pm[i].win,pm[i].tie, pm[i].lose);
    }

    int arr[3][3]={
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };
    int* iscore[]={&pm[0].win, &pm[0].tie, &pm[0].lose};
    printf("total\n");
    if (win_check(checkArr(arr), turn, iscore)>=0.8){
        Sleep(1000);
        printf("you guys are win\n");
    }
    else{
        Sleep(1000);
        printf("you lose\n");
    }
    return 0;
}