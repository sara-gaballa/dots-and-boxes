#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
int play , loadgame , TOP10 , Exit ,  player1 ,player2  ,easy=0, hard=0 , b , f ,g;
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
struct top10{
char name[100];
int score=0;
}top1,top2,top3,top4,top5,top6,top7,top8,top9,top10;
struct compmoves{
int x1,y1,x2,y2;
}comp;

#endif // STRUCTS_H_INCLUDED
