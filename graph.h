#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED
#include<bits/stdc++.h>
#include<SDL2/SDL.h>
using namespace std;
void DrawCircle(SDL_Renderer * renderer,int centreX,int centreY,int radius,int radius2,int ALIAS=1,int R=255,int G=255,int B=255)
{
bool MAT[radius*ALIAS*2+ALIAS+1][radius*ALIAS*2+ALIAS+1];
radius2=radius-radius2;
for(int i=-radius*ALIAS;i<=radius*ALIAS;i++){
for(int l=-radius*ALIAS;l<=radius*ALIAS;l++){
int X=i,Y=l;
if(X*X+Y*Y-radius*radius*ALIAS*ALIAS<=0&&X*X+Y*Y-radius2*radius2*ALIAS*ALIAS>=0){
MAT[i+radius*ALIAS][l+radius*ALIAS]=1;
}
else
MAT[i+radius*ALIAS][l+radius*ALIAS]=0;
}
}
for(int i=-radius*ALIAS;i<radius*ALIAS;i+=ALIAS){
for(int l=-radius*ALIAS;l<radius*ALIAS;l+=ALIAS){
int TOT=0;
for(int x=0;x<ALIAS;x++)
for(int z=0;z<ALIAS;z++)
TOT+=MAT[i+x+radius*ALIAS][l+z+radius*ALIAS]*255;
TOT/=ALIAS*ALIAS;
SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
SDL_SetRenderDrawColor(renderer,R,G,B,TOT);
SDL_RenderDrawPoint(renderer,centreX+i/ALIAS+ALIAS/2,centreY+l/ALIAS+ALIAS/2);
}
}
}
void DRAWLINE(SDL_Renderer *Renderer,int x1,int y1,int x2,int y2,int W){
SDL_Rect A;
A.x=min(x1,x2),A.y=min(y1,y2);
if(x1==x2)
A.h=abs(y2-y1),A.w=W;
else
A.w=abs(x2-x1),A.h=W;
SDL_SetRenderDrawColor(Renderer,255,255,255,255);
SDL_RenderFillRect(Renderer,&A);
}
#endif // CIRCLE_H_INCLUDED
