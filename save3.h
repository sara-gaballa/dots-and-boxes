#ifndef SAVE3_H_INCLUDED
#define SAVE3_H_INCLUDED
#include "structs.h"
void save3(){
if (loadgame==0){
FILE *save3;
save3=fopen("save3.txt","w");
fprintf(save3,play1.name);
if(player1==1){
fprintf(save3,"\n");}
fprintf(save3,play2.name);
fprintf(save3,"\n%d\n%d\n",play1.score,play2.score);
fprintf(save3,"%d\n",play1.moves);
fprintf(save3,"%d\n",play2.moves);
fprintf(save3,"%d\n",num_of_lines );
fprintf(save3,"%d\n",timenew);
fprintf(save3,"%d\n",N);
fprintf(save3,"%d\n",player1);
fprintf(save3,"%d\n",player2);
fprintf(save3,"%d\n",p1.color);
fclose(save3);
FILE *broadsave3;
broadsave3 = fopen("broadsave3.txt","w");
for(int i=0;i<10;i++){
for(int l=0;l<10;l++)
for(int x=0;x<10;x++)
for(int z=0;z<10;z++)
fprintf(broadsave3,"%d\n",adj[i][l][x][z]);
}
fprintf(broadsave3,"\n");
for(int i=0;i<9;i++){
for(int l=0;l<9;l++)
fprintf(broadsave3,"%d\n",GRID[i][l]);}
fclose(broadsave3);
}
if(loadgame==1){

FILE *save3;
save3=fopen("save3.txt","r");
if(save3 == NULL){
    printf(RED"\n\n\n\t\t\t\tERROR SAVE A GAME FIRST"RESET);

    exit(0);
}
fgets(play1.name,50,save3);
fgets(play2.name,50,save3);
fscanf(save3,"%d%d%d%d%d%d",&play1.score,&play2.score,&play1.moves,&play2.moves,&num_of_lines,&timenew);
fscanf(save3,"%d",&N);
fscanf(save3,"%d",&player1);
fscanf(save3,"%d",&player2);
fscanf(save3,"%d",&p1.color);
fclose(save3);
FILE *broadsave3;
broadsave3 = fopen("broadsave3.txt","r");
for(int i=0;i<10;i++){
for(int l=0;l<10;l++)
for(int x=0;x<10;x++)
for(int z=0;z<10;z++)
fscanf(broadsave3,"%d",&adj[i][l][x][z]);
}
for(int i=0;i<9;i++){
for(int l=0;l<9;l++)
fscanf(broadsave3,"%d",&GRID[i][l]);}
fclose(broadsave3);

}}


#endif // SAVE3_H_INCLUDED
