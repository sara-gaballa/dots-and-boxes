#ifndef SAVE1_H_INCLUDED
#define SAVE1_H_INCLUDED
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"
#include "structs.h"
save1(){
if (loadgame==0){
FILE *save1;
save1=fopen("save1.txt","w");
fprintf(save1,"%d",player1);
//fprintf(save1,"____________________________________\n|");
//fprintf(save1,"\nPLAYER 1:  ");
//fprintf(save1,play1.name);
fprintf(save1,"%d %d",play1.score,play2.score);
//fprintf(save1,"\n\nMOVES :  %d",play1.moves);
//fprintf(save1,"\n|\n____________________________________\n|");
//fprintf(save1,"\nPLAYER 2:  ");

/*fprintf(save1,"\n\nMOVES :  %d",play2.moves);
fprintf(save1,"\n|\n____________________________________\n");
fprintf(save1,"\n\n\nNUM OF LINES LEFT =   %d",num_of_lines );
fprintf(save1,CYAN"for undo press=X\nfor exit the game press esc"RESET);
fprintf(save1,RED"\n\n\n\n\n\n\n\n\n\n\nINSTUCTIONS:\n"RESET);
fprintf(save1,CYAN"TO MOVE: \npress any of the 4 arrow keys to move along the dots \nTO DRAW:\n press space with arrows"RESET);
fprintf(save1,RED"\n\nTIMMMMMME    %d"RESET,timenew);*/
fclose(save1);
}
if(loadgame==1){

FILE *save1;
save1=fopen("save1.txt","r");
fprintf(save1,"%d",player2);
//printf(YELLOW"____________________________________\n|"RESET);
//printf(BLUE"\nPLAYER 1:  "RESET);
//play1.name=fgets(play1.name,50,save1);
fscanf(save1,"%d %d %d",&player1,&play1.score,&play2.score);

/*printf(BLUE"\n\nSCORE: %d"RESET,play1.score);
printf(BLUE"\n\nMOVES :  %d"RESET,play1.moves);
printf(YELLOW"\n|\n____________________________________\n|"RESET);
printf(GREEN"\nPLAYER 2:  "RESET);

if(player1==1){
strncpy(play2.name,"computer",50);
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
printf(MAGENTA"\n\n\nNUM OF LINES LEFT =   %d"RESET,num_of_lines );
}

printf(CYAN"for undo press=X\nfor exit the game press esc"RESET);
printf(RED"\n\n\n\n\n\n\n\n\n\n\nINSTUCTIONS:\n"RESET);
printf(CYAN"TO MOVE: \npress any of the 4 arrow keys to move along the dots \nTO DRAW:\n press space with arrows"RESET);
printf(RED"\n\nTIMMMMMME    %d"RESET,timenew);
}*/
}
}
#endif
