#ifndef SAVE2_H_INCLUDED
#define SAVE2_H_INCLUDED
#include "structs.h"

void save2(){
if (loadgame==0){
FILE *save2;
save2=fopen("save2.txt","w");

fprintf(save2,play1.name);
if(player1==1){
fprintf(save2,"\n");}
fprintf(save2,play2.name);
fprintf(save2,"\n%d\n%d\n",play1.score,play2.score);
fprintf(save2,"%d\n",play1.moves);
fprintf(save2,"%d\n",play2.moves);
fprintf(save2,"%d\n",num_of_lines );
fprintf(save2,"%d\n",timenew);
fprintf(save2,"%d\n",N);
fprintf(save2,"%d\n",player1);
fprintf(save2,"%d\n",player2);
fclose(save2);
FILE *broadsave2;
broadsave2 = fopen("broadsave2.txt","w");
for(int i=0;i<10;i++){
for(int l=0;l<10;l++)
for(int x=0;x<10;x++)
for(int z=0;z<10;z++)
fprintf(broadsave2,"%d\n",adj[i][l][x][z]);
}
fprintf(broadsave2,"\n");
for(int i=0;i<9;i++){
for(int l=0;l<9;l++)
fprintf(broadsave2,"%d\n",GRID[i][l]);}
fclose(broadsave2);
}
if(loadgame==1){

FILE *save2;
save2=fopen("save2.txt","r");
if(save2 == NULL){
    printf(RED"\n\n\n\t\t\t\tERROR SAVE A GAME FIRST"RESET);
    exit(0);
}
fgets(play1.name,50,save2);
fgets(play2.name,50,save2);
fscanf(save2,"%d%d%d%d%d%d",&play1.score,&play2.score,&play1.moves,&play2.moves,&num_of_lines,&timenew);
fscanf(save2,"%d",&N);
fscanf(save2,"%d",&player1);
fscanf(save2,"%d",&player2);
fclose(save2);
FILE *broadsave2;
broadsave2 = fopen("broadsave2.txt","r");
for(int i=0;i<10;i++){
for(int l=0;l<10;l++)
for(int x=0;x<10;x++)
for(int z=0;z<10;z++)
fscanf(broadsave2,"%d",&adj[i][l][x][z]);
}
for(int i=0;i<9;i++){
for(int l=0;l<9;l++)
fscanf(broadsave2,"%d",&GRID[i][l]);}
fclose(broadsave2);

}}




#endif // SAVE2_H_INCLUDED
