#ifndef AI_H_INCLUDED
#define AI_H_INCLUDED
#include"graph.h"
void DRAWLINE(void);
struct coordinates{
int x;int y;
}cor[10][10];//coordinates
int RAND(int L,int R){
return rand()%(R-L+1)+L;
}
void compplay(){//Checks who took which squares or not
bool flag=0;
for(int i=0;i<9;i++){
for(int l=0;l<9;l++){
if(adj[i][l][i][l+1]+adj[i][l][i+1][l]+adj[i+1][l][i+1][l+1]+adj[i][l+1][i+1][l+1]==3&&GRID[i][l]==0){
        if(adj[i][l][i][l+1]){
        DRAWLINE(renderer,cor[i][l].x,cor[i][l].y,cor[i][l+1].x,cor[i][l+1].y,8);
        }
        else if(adj[i][l][i+1][l]){
        DRAWLINE(renderer,cor[i][l].x,cor[i][l].y,cor[i+1][l].x,cor[i+1][l].y,8);
        }
        else if(adj[i+1][l][i+1][l+1]){
        DRAWLINE(renderer,cor[i+1][l].x,cor[i+1][l].y,cor[i+1][l+1].x,cor[i+1][l+1].y,8);
        }
        else if(adj[i][l+1][i+1][l+1]){
        DRAWLINE(renderer,cor[i][l+1].x,cor[i][l+1].y,cor[i+1][l+1].x,cor[i+1][l+1].y,8);
        }
flag=1;
GRID[i][l]=2;
}
}
}
}

#endif
