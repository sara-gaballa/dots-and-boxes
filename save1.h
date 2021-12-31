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
//fprintf(save1,"%d\n",player1);
//fprintf(save1,"%d\n",player2);
fprintf(save1,play1.name);
//fprintf(save1,"\n");
//fprintf(save1,play2.name);
fprintf(save1,"\n%d\n%d\n",play1.score,play2.score);
fprintf(save1,"%d\n",play1.moves);
fprintf(save1,"%d\n",play2.moves);
fprintf(save1,"%d\n",num_of_lines );
fprintf(save1,"%d\n",timenew);
fprintf(save1,"%d",N);
fclose(save1);
}
if(loadgame==1){

FILE *save1;
save1=fopen("save1.txt","r");
//fscanf(save1,"%d",&player1);
//fscanf(save1,"%d",&player2);
fgets(play1.name,50,save1);
//fgets(play2.name,50,save1);
//fgets(play2.name,50,save1);
fscanf(save1,"%d%d%d%d%d%d",&play1.score,&play2.score,&play1.moves,&play2.moves,&num_of_lines,&timenew);
fscanf(save1,"%d",&N);
fclose(save1);
}}
#endif
