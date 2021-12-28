#ifndef AI_H_INCLUDED
#define AI_H_INCLUDED

int RAND(int L,int R){
return rand()%(R-L+1)+L;
}
void compplay(){//Checks who took which squares or not
bool flag=0;
for(int i=0;i<9;i++){
for(int l=0;l<9;l++){
if(adj[i][l][i][l+1]+adj[i][l][i+1][l]+adj[i+1][l][i+1][l+1]+adj[i][l+1][i+1][l+1]==3&&GRID[i][l]==0){
flag=1;
GRID[i][l]=p;
}
}
}
}

#endif
