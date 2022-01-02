#ifndef LOGIC_H_INCLUDED
#define LOGIC_H_INCLUDED
#include"structs.h"
#include"view.h"
//FILE *broadsave;
//broadsave = fopen("broadsave.txt","w");
bool adj[10][10][10][10];
int GRID[10][10];//Sees which square is taken by who
void CONNECT(int x1,int y1,int x2,int y2){
adj[x1][y1][x2][y2]=adj[x2][y2][x1][y1]=1;
//fprintf(broadsave,"%d",adj[x1][y1][x2][y2]);
num_of_lines--;
if(p1.color==0){
    play1.moves++;
}
else{
    play2.moves++;
}
system("cls");
view();
}
void DISCONNECT(int x1,int y1,int x2,int y2){//undo
adj[x1][y1][x2][y2]=adj[x2][y2][x1][y1]=0;
}
bool UPDGRID(int p){//Checks who took which squares or not
int flag=0;
for(int i=0;i<9;i++){
for(int l=0;l<9;l++){
if(adj[i][l][i][l+1]==1&&adj[i][l][i+1][l]==1&&adj[i+1][l][i+1][l+1]==1&&adj[i][l+1][i+1][l+1]==1&&GRID[i][l]==0){
flag++;
GRID[i][l]=p;
}
}
}
    if(p==1){
        play1.score=play1.score+flag;
        system("cls");
        view();
    }
    else if(p==2){
        play2.score=play2.score+flag;
        system("cls");
        view();
    }


return flag;
}
//fclose(broadsave);
#endif // LOGIC_H_INCLUDED
