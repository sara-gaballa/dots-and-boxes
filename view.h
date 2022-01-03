#ifndef VIEW_H_INCLUDED
#define VIEW_H_INCLUDED
#include"structs.h"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"
#include"TOP10.h"
#include"logic.h"
void clean(void);
void view(){
printf(YELLOW"____________________________________\n|"RESET);
printf(BLUE"\nPLAYER 1:  "RESET);
for(int i=0;play1.name[i]!='\0' && play1.name[i]!='\n';i++){
    printf("%c",play1.name[i]);
}
printf(BLUE"\n\nSCORE: %d"RESET,play1.score);
printf(BLUE"\n\nMOVES :  %d"RESET,play1.moves);
printf(YELLOW"\n|\n____________________________________\n|"RESET);
printf(GREEN"\nPLAYER 2:  "RESET);
if(player1==1){
for(int i=0;play2.name[i]!='\0' &&play2.name[i]!='\n';i++){
    printf("%c",play2.name[i]);
}
printf(GREEN"\n\nSCORE: %d"RESET,play2.score);
printf(GREEN"\n\nMOVES :  %d"RESET,play2.moves);
printf(YELLOW"\n|\n____________________________________\n"RESET);
printf(MAGENTA"\n\n\nNUM OF LINES LEFT =   %d"RESET,num_of_lines );

}
else if(player2==1){
for(int i=0;play2.name[i]!='\0' &&play2.name[i]!='\n';i++){
    printf("%c",play2.name[i]);
}
printf(GREEN"\n\nSCORE: %d"RESET,play2.score);
printf(GREEN"\n\nMOVES :  %d"RESET,play2.moves);
printf(YELLOW"\n|\n____________________________________\n"RESET);
printf(MAGENTA"NUM OF LINES LEFT =   %d"RESET,num_of_lines );
}
printf(RED"\nTIME = %d\n"RESET,timenew);
if(loadgame==0){
printf(CYAN"for undo press=X\nfor exit the game press esc"RESET);
printf(RED"\nINSTUCTIONS:\n"RESET);
printf(CYAN"TO MOVE:\npress any of the 4 arrow keys to move along the dots \nTO DRAW:\n press space with arrows"RESET);
}
if(num_of_lines==0){
    if(play1.score>play2.score){
        printf(CYAN"\n\n\n\n\n\n\n\t\tCONGRATLATIONS "RESET);
        for(int i=0;play1.name[i]!='\0' && play1.name[i]!='\n';i++){
        printf(MAGENTA"%c"RESET,play1.name[i]);
        }
        printf( YELLOW"\t\tYOUR SCORE IS: %d"RESET,play1.score);
        SDL_Quit();
    }else if (play1.score<play2.score &&strcmp(compt,play2.name)!=0){
         printf(CYAN"\n\n\n\n\n\n\n\t\tCONGRATLATIONS "RESET);
        for(int i=0;play2.name[i]!='\0' && play2.name[i]!='\n';i++){
        printf(MAGENTA"%c"RESET,play2.name[i]);
        }
        printf(YELLOW"\t\tYOUR SCORE IS: %d"RESET,play2.score);
        SDL_Quit();
    }
    else if(play1.score==play2.score){

           printf(RED"\n\n\t\tDRAW , TRY AGAIN ^^"RESET);
           SDL_Quit();
    }
    else{
           printf(RED"\n\n\t\tYOU LOST, TRY AGAIN ^^"RESET);
           SDL_Quit();
    }

}
if(num_of_lines==0 && (play1.score+play2.score==(N-1)*(N-1))){
    top();
    char SARA[2];
    printf(RED"\npress 1 to return "RESET);
    printf(RED"\npress 0 to exit "RESET);
    scanf("%s",&SARA);
    while(1){
        int O = SARA[0]-'0';
    if(O == 1){
    play=0;
    clean();
    main(_argc , _argv);
    break;}
    else if ( O == 0){
        system("taskkill/IM cb_console_runner.exe");
        exit(0);
    }
    else { printf("ERROE");
     scanf("%s",&SARA);}
    }
}

}

#endif // VIEW_H_INCLUDED
