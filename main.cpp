#include "SDL2/SDL.h"
#include "stdio.h"
#include"stdlib.h"
#include"math.h"
#include "graph.h"
#include "logic.h"
#include"structs.h"
#include"view.h"
#include"ai.h"
#include"save1.h"
#include"string.h"
#include"save2.h"
#include"save3.h"
#include"TOP10.h"
#include"debug_final_save.h"
bool changed;
int S=0,LO=0;//for loading and saving
int last=0;
SDL_Event event;
const int GRAPHICS=6;//Aliasing
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
else if(key==27){//esc
        SDL_Quit();
        printf(CYAN"\nchoose [1]save1 , [2]save2 , [3]save3"RESET);
        char out[2];
        char jk[2];
        scanf("%s",&out);
        while(1){
                 S=out[0]-'0';
        if(S==1){
            save1();
            loadgame=0;
            printf("\nENTER 1 to return: ");
            printf("\nENTER 0 to exit: ");
            scanf("%s",&jk);
            while (1){
                    int F=jk[0]-'0';
            if(F==1){
                clean();
                main(_argc , _argv); break;
            }
            else if (F==0){
            system("taskkill/IM cb_console_runner.exe");
            exit(0);}
            else {
                printf("Erorr");
                scanf("%s",&jk);
            }

        }break;
        }
         else if(S==2){
            save2();
            loadgame=0;
            printf("\nENTER 1 to return: ");
            printf("\nENTER 0 to exit: ");

            scanf("%s",&jk);
            while (1){
                    int F=jk[0]-'0';
            if(F==1){
                clean();
                main(_argc , _argv); break;
            }
            else if (F==0){
            system("taskkill/IM cb_console_runner.exe");
            exit(0);}
            else {
                printf("Erorr");
                scanf("%s",&jk);
            }

        }break;
        }
         else if(S==3){
            save3();
            loadgame=0;
            printf("\nENTER 1 to return: ");
            printf("\nENTER 0 to exit: ");

            scanf("%s",&jk);
            while (1){
                    int F=jk[0]-'0';
            if(F==1){
                clean();
                main(_argc , _argv); break;
            }
            else if (F==0){
            system("taskkill/IM cb_console_runner.exe");
            exit(0);}
            else {
                printf("Erorr");
                scanf("%s",&jk);
            }

        }break;
        }
        else printf(RED"Erorr"RESET); scanf("%s",&out);
        }

}
else if(key==117 && UNDO.SIZE>0 && player2==1){//u ==undo
PP=UNDO.top();//last move(corr)
if(p1.color!=PP.PLR){
swap(p1,p2);}//player now is not the same as the past player
DISCONNECT(PP.x1,PP.y1,PP.x2,PP.y2,PP.PLR);//remove the line
REDO.push(PP);//save this point in case of redo
UNDO.pop();//remove it by size of stack--
UPDGRID(p1.color);//to remove the colored square
}
else if(key== 114 && REDO.SIZE>0 && player2==1){//r == redo
PP=REDO.top();
if(p1.color==PP.PLR && !UPDGRID(PP.PLR+1)){//color is the same and no square is about to be made before connect
swap(p1,p2);}
CONNECT(PP.x1,PP.y1,PP.x2,PP.y2,PP.PLR,1);//line draw
REDO.pop();//remove the saved one
if(UPDGRID(PP.PLR+1) && p1.color!=PP.PLR){//after connect there if there is a square made by this color swap it
swap(p1,p2);}
}
else if(key==32){//hit space
Toggle=!Toggle;//if(Toggle==1){Toggle=0;}else{Toggle=1;}
}
p1.x+=N,p1.x%=N;  //limits
p1.y+=N,p1.y%=N;  //limits
}

void DRAW(SDL_Renderer *renderer,int x,int y,int r,int g,int b){// draw colored square and toggle circle and
for(int i=0;i<N-1;i++){
for(int l=0;l<N-1;l++){
if(GRID[i][l]==1){
SDL_SetRenderDrawColor(renderer,0, 0, 255, 255); //blue
}
else if(GRID[i][l]==2){
SDL_SetRenderDrawColor(renderer,0, 255, 0,255); //green
}
if(GRID[i][l]!=0){
SDL_Rect A;
A.x=cor[i][l].x,A.y=cor[i][l].y;//corrdinates of square
A.h=cor[i+1][l].x-cor[i][l].x,A.w=cor[i][l+1].y-cor[i][l].y;// height and width
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
DrawCircle(renderer,cor[i][l].x,cor[i][l].y,15,3,GRAPHICS);//draw the loop of circles
if(i==x&&l==y){
DrawCircle(renderer,cor[i][l].x,cor[i][l].y,13,13,GRAPHICS,r,g,b); //blue or green circle
}
}
}
}
int converter(){//press toggle
compplay();
p1.x=comp.x1;
p1.y=comp.y1;
p1.ox=comp.x1;
p1.oy=comp.y1;
if(comp.x2<comp.x1){
    return 1073741904;//left
}
if(comp.x2>comp.x1){
    return 1073741903;//right
}
if(comp.y2<comp.y1){
    return 1073741906;//up
}
if(comp.y2>comp.y1){
    return 1073741905;//down
}
}
void upd(SDL_Renderer *renderer){
timenew=(clock()-last)/1000;//time
SDL_SetRenderDrawColor(renderer,10,10,10,255); //black background
SDL_RenderClear(renderer);
changed=0;
if((p1.ox!=p1.x||p1.oy!=p1.y)&&Toggle){
if(!adj[p1.ox][p1.oy][p1.x][p1.y]&&(abs(p1.ox-p1.x)+abs(p1.oy-p1.y))==1){//Checks if movement adjacent
CONNECT(p1.ox,p1.oy,p1.x,p1.y,p1.color);//what connects the two points
if(!UPDGRID(p1.color+1)){
changed=1;
}
}
Toggle=0;
}
p1.ox=p1.x,p1.oy=p1.y;
if(changed){
if(!(p1.color==1 && player1==1)){
p2.ox=p2.x=p1.x;
p2.oy=p2.y=p1.y;}
swap(p1,p2);
}
if(p1.color==1){
DRAW(renderer,p1.x,p1.y,0,255,0);//green circle
}
else{
DRAW(renderer,p1.x,p1.y,0,0,255);// blue circle
}
for(int i=0;i<N;i++){
for(int l=0;l<N;l++){
if(adj[i][l][i+1][l]==1){
DRAWLINE(renderer,cor[i][l].x,cor[i][l].y,cor[i+1][l].x,cor[i+1][l].y,8);
}
if(adj[i][l][i][l+1]){
DRAWLINE(renderer,cor[i][l].x,cor[i][l].y,cor[i][l+1].x,cor[i][l+1].y,8);
}
}
}
}
void sdl_page(){
SDL_Window *window;                    // Declare a pointer
SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2
window = SDL_CreateWindow(
"DOTS AND BOXES",                  // window title
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
//LT=SDL_GetTicks();
for(int i=0;i<N;i++){// draw circles loop
for(int l=0;l<N;l++){
cor[i][l].x=i*100+20;
cor[i][l].y=l*100+80;
}
}
SDL_RenderPresent(renderer);
//LT=SDL_GetTicks();
while(1){// gui main game loop
if(p1.color==1 && player1==1){
    Toggle=1;
    TOGGLE(converter());
}
else{
while(SDL_PollEvent(&event)){
if(event.type==SDL_QUIT){
        SDL_Quit();
        printf(CYAN"\nchoose [1]save1 , [2]save2 , [3]save3"RESET);
        char out[2];
        scanf("%s",&out);
        while(1){
                 S=out[0]-'0';
        if(S==1){
            save1();
            loadgame=0;
             char jk[2];
            printf("\nENTER 1 to return: ");
            printf("\nENTER 0 to exit: ");
            scanf("%s",&jk);
            while (1){
                    int F=jk[0]-'0';
            if(F==1){
                clean();
                hard=0;
                easy=0;
                main(_argc , _argv); break;
            }
            else if (F==0){
            system("taskkill/IM cb_console_runner.exe");
            exit(0);}
            else {
                printf("Erorr");
                scanf("%s",&jk);
            }

        }
        }
         else if(S==2){
            save2();
            loadgame=0;
             char jk[2];
            printf("\nENTER 1 to return: ");
            printf("\nENTER 0 to exit: ");
            scanf("%s",&jk);
            while (1){
                    int F=jk[0]-'0';
            if(F==1){
                clean();
                hard=0;
                easy=0;
                main(_argc , _argv); break;
            }
            else if (F==0){
            system("taskkill/IM cb_console_runner.exe");
            exit(0);}
            else {
                printf("Erorr");
                scanf("%s",&jk);
            }

        }
        }
         else if(S==3){
            save3();
            loadgame=0;
            char jk[2];
            printf("\nENTER 1 to return: ");
            printf("\nENTER 0 to exit: ");
            scanf("%s",&jk);
            while (1){
                    int F=jk[0]-'0';
            if(F==1){
                clean();
                hard=0;
                easy=0;
                main(_argc , _argv); break;
            }
            else if (F==0){
            system("taskkill/IM cb_console_runner.exe");
            exit(0);}
            else {
                printf("Erorr");
                scanf("%s",&jk);
            }

        }
        }
        else printf(RED"Erorr"RESET); scanf("%s",&out);
        }
}

else if(event.type==SDL_KEYDOWN){// activate the keyboard keys
TOGGLE(event.key.keysym.sym);
}
}
}
upd(renderer);
SDL_RenderPresent(renderer);
LT=SDL_GetTicks();
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
int a=0;
p1.color=0;//player one blue
p2.color=1;//player two green
system("cls");
printf(CYAN"\n\n  *****************************************************************************************************************\n"RESET);
printf("\t\t\t");
printf( MAGENTA R"(      _       _                         _   _                        )" RESET);
printf("\n");
printf("\t\t\t");
printf( CYAN R"(   __| | ___ | |_ ___    __ _ _ __   __| | | |__   _____  _____  ___ )"RESET);
printf("\n");
printf("\t\t\t");
printf( MAGENTA R"(  / _` |/ _ \| __/ __|  / _` | '_ \ / _` | | '_ \ / _ \ \/ / _ \/ __|)"RESET);
printf("\n");
printf("\t\t\t");
printf( BLUE R"( | (_| | (_) | |_\__ \ | (_| | | | | (_| | | |_) | (_) >  <  __/\__ \)"RESET);
printf("\n");
printf("\t\t\t");
printf( CYAN R"(  \__,_|\___/ \__|___/  \__,_|_| |_|\__,_| |_.__/ \___/_/\_\___||___/)"RESET);

    printf(CYAN"\n\n  *****************************************************************************************************************\n"RESET);
printf("\n\n\n\n");
printf(  MAGENTA "\t \t \t [1] PLAY\n\n" RESET); printf(CYAN "\t \t \t [2] LOAD GAME\n\n"RESET);
printf(MAGENTA "\t \t \t [3] TOP TEN\n\n"RESET);
printf(BLUE "\t \t \t [4] EXIT\n\n"RESET);
printf("\n");


char input[2]={} ,num[2]={} ,hardness[2]={} ,dim[2]={} ;
printf(CYAN "ENTER 1 or 2 or 3 or 4:  " RESET);

scanf("%s",&input);
while(1){
         a = input[0]-'0';
   if(a==1){
    play=1; break;
   }
   else if (a==2){
    loadgame=1;
     break;
   }
   else if (a==3){
    TOP10=1; break;
   }
   else if (a==4){
    system("taskkill/IM cb_console_runner.exe");
        exit(0);
   }
   else
    printf(RED "Error enter a valid number !" RESET);
    scanf("%s",&input);
}
while(TOP10==1){
    top();
    system("cls");
    printf(BLUE"\n\t\t\t\t\t TOP 10 LIST\n"RESET);
    overwrriten();
    sorting();
    for(int i=0;i<10;i++){
    printf(YELLOW"[%d]"RESET,i+1);
    printf(CYAN"\nNAME: %sSCORE: %d\n"RESET,topn[i].name,topn[i].score);
    }
char SARA[2];
    printf(RED"\npress 1 to return "RESET);
    printf(RED"\npress 0 to exit "RESET);
    scanf("%s",&SARA);
    while(1){
        int O = SARA[0]-'0';
    if(O == 1){
    TOP10=0;
    clean();
    main(_argc , _argv);
    break;}
    else if ( O == 0){
        system("taskkill/IM cb_console_runner.exe");
        exit(0);
    }
    else { printf("ERROE");
     scanf("%s",&SARA);}
    }
    break;
}
while(loadgame==1){

    system("cls");
    printf(CYAN"choose [1]save1 ,[2]save2,[3]save3"RESET);
    char in[2];
    scanf("%s",&in);
    while(1){
            LO=in[0]-'0';
    if(LO==1){
            system("cls");
            save1();
            loadgame=0;
            break;
    }
    else if(LO==2){
            system("cls");
            save2();
            loadgame=0;
            break;
    }
    else if(LO==3){
            system("cls");
            save3();
            loadgame=0;
            break;
    }
    else {
        printf("ERROR");
        scanf("%s",&in);
    }}
    view();
    if(N==3){
    WIDTH=350,HEIGHT=350; }
    if(N==4){
    WIDTH=550,HEIGHT=550; }
    if(N==5){
    WIDTH=650,HEIGHT=650; }
    if(N==6){
    WIDTH=750,HEIGHT=750;}
    if(N==7){
    WIDTH=750,HEIGHT=750;}
    sdl_page();
   break;
}
while(play==1){
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
int y=1;
play2.name[0]='c';
play2.name[1]='o';
play2.name[2]='m';
play2.name[3]='p';
play2.name[4]='u';
play2.name[5]='t';
play2.name[6]='e';
play2.name[7]='r';
compt[0]='c';
compt[1]='o';
compt[2]='m';
compt[3]='p';
compt[4]='u';
compt[5]='t';
compt[6]='e';
compt[7]='r';
while( y==1){
        //open
gets(play1.name);
for(int i=0;play1.name[i]!='\0' &&play1.name[i]!='\n';i++){
    if(play1.name[i]!='\0' && play1.name[i]!='\n'){
            //save
            y=0; break; }}
}
//close
break;}

else if (b==2){
player2=1;
printf(BLUE"\n ENTER YOUR NAME:"RESET);
int x=1;

while( x==1){
        //open
fgets(play1.name,50,stdin);
for(int i=0;play1.name[i]!='\0' &&play1.name[i]!='\n';i++){
    if(play1.name[i]!='\0' && play1.name[i]!='\n'){x=0;
    break;
    }
    }
}
printf(GREEN"\n ENTER YOUR FRIEND NAME:"RESET);
int z=1;
while( z==1){
    //open
fgets(play2.name,100,stdin);
for(int i=0;play2.name[i]!='\0' &&play2.name[i]!='\n';i++){
    if(play2.name[i]!='\0' && play2.name[i]!='\n'){
        //save
            z=0; break; }}
}

//close
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
      printf(GREEN"\n enter the dim (3 or 4) : "RESET);
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
      printf(RED"\n enter the dim (5 or 6 or 7) : "RESET);
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
num_of_lines=2*N*(N-1);
if( player2==1){
system("cls");
view();
last=clock();
sdl_page();
}
if(player1==1){
system("cls");
view();
last=clock();
sdl_page();

}
}
}


