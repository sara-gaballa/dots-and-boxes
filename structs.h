#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
struct scoresANDname{
int score=0;
char name[50];
}play1,play2;
struct coordinates{
int x;int y;
}cor[10][10];//coordinates
struct player{
int x=0,y=0,ox=-1,oy=-1;
bool color;
int time=0;
}p1,p2;


#endif // STRUCTS_H_INCLUDED