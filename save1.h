#ifndef SAVE1_H_INCLUDED
#define SAVE1_H_INCLUDED
#include "structs.h"
 void save1(){
if (loadgame==0){
FILE *save1;
save1=fopen("save1.txt","w");
fprintf(save1,play1.name);
if(player1==1){
fprintf(save1,"\n");}
fprintf(save1,play2.name);
fprintf(save1,"\n%d\n%d\n",play1.score,play2.score);
fprintf(save1,"%d\n",play1.moves);
fprintf(save1,"%d\n",play2.moves);
fprintf(save1,"%d\n",num_of_lines );
fprintf(save1,"%d\n",timenew);
fprintf(save1,"%d\n",N);
fprintf(save1,"%d\n",player1);
fprintf(save1,"%d\n",player2);
fprintf(save1,"%d\n",p1.color);
fclose(save1);
FILE *broadsave1;
broadsave1 = fopen("broadsave1.txt","w");
for(int i=0;i<10;i++){
for(int l=0;l<10;l++)
for(int x=0;x<10;x++)
for(int z=0;z<10;z++)
fprintf(broadsave1,"%d\n",adj[i][l][x][z]);
}
fprintf(broadsave1,"\n");
for(int i=0;i<9;i++){
for(int l=0;l<9;l++)
fprintf(broadsave1,"%d\n",GRID[i][l]);}
fclose(broadsave1);
}
if(loadgame==1){

FILE *save1;
save1=fopen("save1.txt","r");
if(save1 == NULL){
    printf(RED"\n\n\n\t\t\t\tERROR SAVE A GAME FIRST"RESET);
    printf("\n\n\n\t\t\t\tpress 1 to return\n ");
    printf("\t\t\t\tpress 0 to exit");
    char E[2];
    int NANCY;
    scanf("%s",&E);
    while(1){
        NANCY=E[0]-'0';

        if(NANCY==1){
                loadgame=0;
            main(_argc , _argv);
            break;
        }
        else if (NANCY==0){
            system("taskkill/IM cb_console_runner.exe");
            exit(0);
        }
        else {
            printf("ERROR");
            scanf("%s",&E);
        }
    }
}
fgets(play1.name,50,save1);
fgets(play2.name,50,save1);
fscanf(save1,"%d%d%d%d%d%d",&play1.score,&play2.score,&play1.moves,&play2.moves,&num_of_lines,&timenew);
fscanf(save1,"%d",&N);
fscanf(save1,"%d",&player1);
fscanf(save1,"%d",&player2);
fscanf(save1,"%d",&p1.color);
fclose(save1);
FILE *broadsave1;
broadsave1 = fopen("broadsave1.txt","r");
for(int i=0;i<10;i++){
for(int l=0;l<10;l++)
for(int x=0;x<10;x++)
for(int z=0;z<10;z++)
fscanf(broadsave1,"%d",&adj[i][l][x][z]);
}
for(int i=0;i<9;i++){
for(int l=0;l<9;l++)
fscanf(broadsave1,"%d",&GRID[i][l]);}
fclose(broadsave1);

}}
#endif
