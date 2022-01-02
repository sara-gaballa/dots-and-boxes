#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
int play , loadgame=0 , TOP10 , Exit ,  player1 ,player2  ,easy=0, hard=0 , b , f ,g;
char compt[50];

int timenew=0;
int WIDTH,HEIGHT,LT,N;
int num_of_lines=0;
struct scoresANDname{
int score=0;
char name[50];
int moves=0;
}play1,play2;
struct coordinates{
int x;int y;
}cor[10][10];//coordinates
struct player{
int x=0,y=0,ox=-1,oy=-1;
bool color;

int time=0;
}p1,p2;
struct tops{
char name[50];
int score=0;
};
struct tops topn[50];
struct compmoves{
int x1,y1,x2,y2;
}comp;


struct point{
int x1,y1,x2,y2;
bool PLR=0;
}PP;
struct{
point arr[301];
int SIZE=0;
void push(point X){
arr[SIZE].x1=X.x1,arr[SIZE].x2=X.x2,arr[SIZE].y1=X.y1,arr[SIZE].y2=X.y2,arr[SIZE].PLR=X.PLR;
SIZE++;
}
void pop(){
if(SIZE)
SIZE--;
}
point top(){
return arr[SIZE];
}
void clear(){
SIZE=0;
}
}UNDO,REDO;

#endif // STRUCTS_H_INCLUDED
