#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
bool adj[10][10][10][10];
int GRID[10][10];
int play=0 , loadgame=0 , TOP10=0 , Exit=0 ,  player1 ,player2  ,easy=0, hard=0 , b , f ,g;
bool Toggle=0;
char compt[50];
int timenew=0;
struct timec{
int seconds=0;
int mins=0;
}t;
int WIDTH,HEIGHT,LT,N;
int num_of_lines=0;
struct scoresANDname{
int score=0;
char name[50];
int moves=0;
}play1,play2;
struct coordinates{
int x=0;int y=0;
}cor[10][10];//coordinates
struct player{
int x=0,y=0,ox=-1,oy=-1;
bool color;
}p1,p2;
struct tops{
char name[50];
int score=0;
};
struct tops topn[50];
struct compmoves{
int x1,y1,x2,y2;
}comp;


struct point{//SAVING THE CORRDINATIES AND THE PLAYER
int x1,y1,x2,y2;
bool PLR=0;//PLAYER
}PP;
struct{
point arr[301];//array of point struct
int SIZE=0;
void push(point X){//passing the last corrdinates to push function
arr[SIZE].x1=X.x1,arr[SIZE].x2=X.x2,arr[SIZE].y1=X.y1,arr[SIZE].y2=X.y2,arr[SIZE].PLR=X.PLR;
SIZE++;
}
void pop(){//removing the last one
if(SIZE)
SIZE--;
}
point top(){//passing the last parameters
return arr[SIZE-1];
}
void clear(){
SIZE=0;
}
}UNDO,REDO;

#endif // STRUCTS_H_INCLUDED
