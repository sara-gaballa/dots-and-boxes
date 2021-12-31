#ifndef AI_H_INCLUDED
#define AI_H_INCLUDED
#include"graph.h"
#include"structs.h"
#include"logic.h"
int RAND(int L,int R){
return rand()%(R-L+1)+L;
}
void compplay(){//Checks who took which squares or not
for(int i=0;i<9;i++){
for(int l=0;l<9;l++){
if((int)adj[i][l][i][l+1]+adj[i][l][i+1][l]+adj[i+1][l][i+1][l+1]+adj[i][l+1][i+1][l+1]==3&&GRID[i][l]==0){

        if(!adj[i][l][i][l+1]){
         comp.x1=i,comp.y1=l,comp.x2=i,comp.y2=l+1;
        }
        else if(!adj[i][l][i+1][l]){
        comp.x1=i,comp.y1=l,comp.x2=i+1,comp.y2=l;
        }
        else if(!adj[i+1][l][i+1][l+1]){
        comp.x1=i+1,comp.y1=l,comp.x2=i+1,comp.y2=l+1;
        }
        else if(!adj[i][l+1][i+1][l+1]){
         comp.x1=i,comp.y1=l+1,comp.x2=i+1,comp.y2=l+1;
        }
        return;

}
}
}
while(1){
    int x=RAND(0,N-1);
    int y=RAND(0,N-1);
    int z=RAND(0,3);
    int x2=x;
    int y2=y;
    if(z==0){
        x2--;
    }
    else if (z==1){
        x2++;
    }
    else if (z==2){
        y2--;
    }
    else if (z==3){
        y2++;
    }
    if(x2 >=0 && x2<N &&y2 >=0 && y2<N){
    if(!adj[x][y][x2][y2]){
    comp.x1=x,comp.y1=y,comp.x2=x2,comp.y2=y2;
    return;
    }
    }

}
}

#endif
