#include "SDL2/SDL.h"
#include "stdio.h"
#include"stdlib.h"
#include"math.h"
#include "graph.h"
#include "logic.h"
#include"structs.h"
#include"view.h"
//#include"ai.h"

bool changed;
bool changed2;
int s1,s2,s3,s4;
int last;
SDL_Event event;
const int GRAPHICS=6;//Aliasing
int WIDTH,HEIGHT,LT,N;

bool Toggle;
void TOGGLE(int key){
if(key==1073741904){//L
p1.x--;
}
else if(key==1073741905){//D
p1.y++;
}
else if(key==1073741903){//R
p1.x++;
}
else if(key==1073741906){//U
p1.y--;
}
else if(key==32){//hit space
Toggle=!Toggle;//if(Toggle==1){Toggle=0;}else{Toggle=1;}
}
p1.x+=N,p1.x%=N;  //limits
p1.y+=N,p1.y%=N;  //limits
}
void ADD(SDL_Renderer *renderer,int x,int y,int R,int G,int B){   //el fun mesh bt3ml haga
DrawCircle(renderer,cor[x][y].x,cor[x][y].y,13,13,GRAPHICS,R,G,B);
}

void DRAW(SDL_Renderer *renderer,int x,int y,int r,int g,int b){
for(int i=0;i<N-1;i++){
for(int l=0;l<N-1;l++){
if(GRID[i][l]==1){
SDL_SetRenderDrawColor(renderer,0, 0, 255, 255); //blue

}
else if(GRID[i][l]==2){
SDL_SetRenderDrawColor(renderer,0, 255, 0,255); //green1
}
if(GRID[i][l]!=0){
SDL_Rect A;
A.x=cor[i][l].x,A.y=cor[i][l].y;
A.h=cor[i+1][l].x-cor[i][l].x,A.w=cor[i][l+1].y-cor[i][l].y;
SDL_RenderFillRect(renderer,&A);
}
}
}
for(int i=0;i<N;i++){
for(int l=0;l<N;l++){
if(i==x&&l==y&&Toggle){
DrawCircle(renderer,cor[i][l].x,cor[i][l].y,15,3,GRAPHICS,255,0,0); //red circle if toggle in on
}
else
DrawCircle(renderer,cor[i][l].x,cor[i][l].y,15,3,GRAPHICS);
if(i==x&&l==y){
DrawCircle(renderer,cor[i][l].x,cor[i][l].y,13,13,GRAPHICS,r,g,b); //blue or green circle
}
}
}
}

void upd(SDL_Renderer *renderer){

//printf("%d\n",(clock()-last)/1000);//time
SDL_SetRenderDrawColor(renderer,30,10,30,255); //black background
SDL_RenderClear(renderer);
changed=0;
if((p1.ox!=p1.x||p1.oy!=p1.y)&&Toggle){
if(!adj[p1.ox][p1.oy][p1.x][p1.y]&&(abs(p1.ox-p1.x)+abs(p1.oy-p1.y))==1){//Checks if movement adjacent
CONNECT(p1.ox,p1.oy,p1.x,p1.y);
if(!UPDGRID(p1.color+1)){
changed=1;
}
}
Toggle=0;
}
p1.ox=p1.x,p1.oy=p1.y;
if(changed){
p2.ox=p2.x=p1.x;
p2.oy=p2.y=p1.y;
swap(p1,p2);
}
if(p1.color==1){
DRAW(renderer,p1.x,p1.y,0,255,0);
}
else{
DRAW(renderer,p1.x,p1.y,0,0,255);
}
for(int i=0;i<N;i++){
for(int l=0;l<N;l++){
if(adj[i][l][i+1][l]==1)
DRAWLINE(renderer,cor[i][l].x,cor[i][l].y,cor[i+1][l].x,cor[i+1][l].y,8);
if(adj[i][l][i][l+1])
DRAWLINE(renderer,cor[i][l].x,cor[i][l].y,cor[i][l+1].x,cor[i][l+1].y,8);
}
}
}
void sdl_page(){
SDL_Window *window;                    // Declare a pointer
SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2
window = SDL_CreateWindow(
"An SDL2 window",                  // window title
SDL_WINDOWPOS_UNDEFINED,           // initial x position
SDL_WINDOWPOS_UNDEFINED,           // initial y position
WIDTH,                               // width, in pixels
HEIGHT,                               // height, in pixels
SDL_WINDOW_OPENGL                  // flags - see below
);
SDL_Renderer* renderer= SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
SDL_SetRenderDrawColor(renderer,30,10,30,255);
SDL_RenderClear(renderer);
LT=SDL_GetTicks();
for(int i=0;i<N;i++){
for(int l=0;l<N;l++){
cor[i][l].x=i*100+20;
cor[i][l].y=l*100+80;
}
}
SDL_RenderPresent(renderer);
LT=SDL_GetTicks();
while(1){
while(SDL_PollEvent(&event)){
//SDL_WaitEvent(&event);
if(event.type==SDL_QUIT)
exit(0);
else if(event.type==SDL_KEYDOWN){
TOGGLE(event.key.keysym.sym);
}
}
if(SDL_GetTicks()-LT>=1000/60.0){
upd(renderer);
SDL_RenderPresent(renderer);
LT=SDL_GetTicks();
}
}
}
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"
int main(int argc, char* argv[]) {
p1.color=0;//player one blue
p2.color=1;//player2 green
system("cls");
printf("\n\n\n\n");
printf( YELLOW "\t \t \t\t \t \tWELCOME DOT AND BOXS" RESET);
printf("\n\n\n\n\n\n\n\n\n");
printf( BLUE "\t \t \t [1] PLAY\n\n" RESET); printf(RED "\t \t \t [2] LOAD GAME\n\n"RESET);
printf(MAGENTA "\t \t \t [3] TOP TEN\n\n"RESET);
printf(GREEN "\t \t \t [4] EXIT\n\n"RESET);
printf("\n");

int play , loadgame , top10 , Exit ,  player1 ,player2  ,easy=0, hard=0 , b , f ,g;
char input[2] ,num[2] ,hardness[2] ,dim[2] ;
printf(GREEN "ENTER 1 or 2 or 3 or 4:  " RESET);

scanf("%s",&input);
while(1){
        int a = input[0]-'0';
   if(a==1){
    play=1; break;
   }
   else if (a==2){
    loadgame=1; break;
   }
   else if (a==3){
    top10=1; break;
   }
   else if (a==4){
    Exit=1; break;
   }
   else
    printf(RED "Error enter a valid number !" RESET);
    scanf("%s",&input);
}
if(play==1){
int player1=0,player2=0;

 system("cls");
 printf(MAGENTA "\n\n\n\n\t \t \t[1]ONE PLAYER"RESET);
printf(CYAN "\n\n\t \t \t[2]TWO PLAYER"RESET);
scanf("%s",&num[0]);
}

while(1){
int b = num[0]-'0';
if(b==1){
player1=1;
printf(BLUE "\n ENTER YOUR NAME:" RESET);
scanf("%s",&play1.name);
break;}

else if (b==2){
player2=1;
printf(BLUE"\n ENTER YOUR NAME:"RESET);
scanf("%s",&play1.name);
printf(GREEN"\n ENTER YOUR FRIEND NAME:"RESET);
scanf("%s",&play2.name);
break;
}
else { printf(RED "ERROR ENTER 1 or 2"RESET);
    scanf("%s",&num[0]);}
}

system("cls");
printf(GREEN"\n\n\n\n\t \t \t[1]EASY"RESET);
printf(RED"\n\n\t \t \t[2]HARD"RESET);
scanf("%s",&hardness[0]);
while(1){
       int f=hardness[0]-'0';
if (f ==1 ){
easy=1;
break;}
else if(f ==2){
hard=1;
break;}
else {
    printf(RED "ERROR ENTER 1 or 2"RESET);
    scanf("%s",&hardness[0]);
}
}

if(easy==1){
      printf("\n enter the dim (3 or 4) : ");
      scanf("%s",&dim[0]);
while (1){
       g = dim[0]-'0';
if(g==3 || g==4){
    if(g==3){
    WIDTH=350,HEIGHT=350; N=3;break;}

    if(g==4){
    WIDTH=550,HEIGHT=550; N=4; break;}
break;
}
else {
printf(RED"ERROR"RESET);
scanf("%s",&dim[0]);
}}}

if(hard==1){
      printf("\n enter the dim (5 or 6 or 7) : ");
      scanf("%s",&dim[0]);
    while(1){
          g = dim[0]-'0';
    if(g==5|| g==6 ||g==7){
    if(g==5){
    WIDTH=650,HEIGHT=650; N=5; break;}

if(g==6){
    WIDTH=750,HEIGHT=750; N=6; break;
}
if(g==7){
    WIDTH=750,HEIGHT=750; N=7; break;
}
break;
}
else {
printf(RED"ERROR"RESET);
scanf("%s",&dim[0]);
}
}}
while( player2==1){
system("cls");
view();
//last=clock();
sdl_page();
}
}



