#ifndef LOGIC_H_INCLUDED
#define LOGIC_H_INCLUDED
#include"structs.h"
#include"view.h"
//Sees which square is taken by who
void CONNECT(int x1,int y1,int x2,int y2,int pl,bool fromRedo=0){
adj[x1][y1][x2][y2]=adj[x2][y2][x1][y1]=1;
num_of_lines--;
if(p1.color==0){
    play1.moves++;
}
else if(p1.color==1){
    play2.moves++;
}
system("cls");
view();
PP.x1=x1,PP.x2=x2,PP.y1=y1,PP.y2=y2,PP.PLR=pl;
UNDO.push(PP);
if(fromRedo==0){
REDO.clear();}
}
void DISCONNECT(int x1,int y1,int x2,int y2,int pl){
num_of_lines++;    //undo
adj[x1][y1][x2][y2]=adj[x2][y2][x1][y1]=0;
if(p1.color==0){
    play1.moves--;
}
else if(p1.color==1){
    play2.moves--;
}
system("cls");
view();
}
bool UPDGRID(int p){//Checks who took which squares or not
int flag=0;
play1.score=0;
play2.score=0;
for(int i=0;i<9;i++){
for(int l=0;l<9;l++){
if(adj[i][l][i][l+1]==1&&adj[i][l][i+1][l]==1&&adj[i+1][l][i+1][l+1]==1&&adj[i][l+1][i+1][l+1]==1){
if(GRID[i][l]==0){
flag++;
GRID[i][l]=p;
}
if (GRID[i][l]==1){
    play1.score++;

}
else{
    play2.score++;
}

}
else if (GRID[i][l]!=0){
    GRID[i][l]=0;
}
}
}
system("cls");
view();
return flag;
}
void clean(){
timenew=0;
p1.x=0;
p1.y=0;
p2.x=0;
p2.y=0;
Toggle=0;
play1.score=0;
play2.score=0;
play1.moves=0;
play2.moves=0;
for(int i=0;i<10;i++){
for(int l=0;l<10;l++)
for(int x=0;x<10;x++)
for(int z=0;z<10;z++)
adj[i][l][x][z]=adj[x][z][i][l]=0;
}
for(int i=0;i<9;i++){
for(int l=0;l<9;l++)
GRID[i][l]=0;
}
}
#endif // LOGIC_H_INCLUDED
