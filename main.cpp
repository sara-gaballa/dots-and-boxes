#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <dos.h>
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

int main (int argc, char const *argv[]) {
  while(1){
        int play=0,load=0,top=0,exit=0;
system("cls");
printf("\n\n\n\n");
    printf( YELLOW "\t \t \t\t \t \tWELCOME DOT AND BOXS" RESET);
    printf("\n\n\n\n\n\n\n\n\n");
printf( BLUE "\t \t \t [1] PLAY\n\n" RESET); printf(RED "\t \t \t [2] LOAD GAME\n\n"RESET);
printf(MAGENTA "\t \t \t [3] TOP TEN\n\n"RESET);
printf(GREEN "\t \t \t [4] EXIT\n\n"RESET);
printf("\n");
char input;
scanf("%d",&input);
while(1){
    if(input ==1 || input ==2 || input ==3 || input ==4 ){
switch(input){
case 1:play=1;break;
case 2:load=1;break;
case 3:top=1;break;
case 4:exit=1;break;
}break;}
else {
    printf(RED"ERROR ENTER 1 OR 2 OR 3 OR 4"RESET); scanf("%d",&input);
}
}


if(play==1){

int num;
int player1=0,player2=0;
char name1[100] , name2[100];
 system("cls");
 printf(MAGENTA "\n\n\n\n\t \t \t[1]ONE PLAYER"RESET);
printf(CYAN "\n\n\t \t \t[2]TWO PLAYER"RESET);
scanf("%d",&num);


while(1){
if(num==1 || num ==2){
switch(num){
case 1:player1=1; printf("\n ENTER YOUR NAME:");  scanf("%s",&name1);

break;
case 2:player2=1; printf("\n ENTER YOUR NAME:");  scanf("%s",&name1);  printf("\n ENTER YOUR FRIEND NAME:");   scanf("%s",&name2);
break;
}
break;
}
else { printf(RED "ERROR ENTER 1 or 2"RESET);
    scanf("%d",&num);}
}
int hardness;
system("cls");
printf(GREEN"\n\n\n\n\t \t \t[1]EASY"RESET);
printf(RED"\n\n\t \t \t[2]HARD"RESET);
scanf("%d",&hardness);
int easy=0, hard=0;
while(1){
if (hardness ==1 || hardness ==2){
switch(hardness){
case 1:easy=1;break;
case 2:hard=1;break;}break;
}

else {
    printf(RED "ERROR ENTER 1 or 2"RESET);
    scanf("%d",&hardness);
}
}

if(hardness==1){
int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:/TURBOC4/BGI");

	circle(80,170,25);
	circle(180,170,25);
    circle(280,170,25);

	circle(80,270,25);
    circle(180,270,25);
    circle(280,270,25);

    circle(80,370,25);
    circle(180,370,25);
    circle(280,370,25);

    outtextxy(75, 165, "1");
   outtextxy(175, 165, "2");
   outtextxy(275, 165, "3");

   outtextxy(75, 265, "4");
   outtextxy(175, 265, "5");
   outtextxy(275, 265, "6");

   outtextxy(75, 365, "7");
   outtextxy(175, 365, "8");
   outtextxy(275, 365, "9");

    outtextxy(100, 10, "|");
    outtextxy(100, 30, "|");
    outtextxy(100, 50, "|");
    outtextxy(100, 70, "|");
    outtextxy(100, 90, "|");

    outtextxy(180, 10, "|");
    outtextxy(180, 30, "|");
    outtextxy(180, 50, "|");
    outtextxy(180, 70, "|");
    outtextxy(180, 90, "|");

    outtextxy(10, 55, "----------------------------------------------------------------");


 if(num==1){
    outtextxy(10, 40, "player1:");
    outtextxy(10, 70, "computer:");
    outtextxy(120, 10, "score:");
    outtextxy(200, 10, "steps:");



	getch();
	closegraph();}
	else if (num==2){
        outtextxy(10, 40, "player1:");
   outtextxy(10, 70, "player2:");
   outtextxy(120, 10, "score:");
   outtextxy(200, 10, "steps:");


	}
}
if(hardness==2){
int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:/TURBOC4/BGI");

	circle(50,150,20);
	circle(120,150,20);
    circle(190,150,20);
    circle(260,150,20);
	circle(330,150,20);

	circle(50,220,20);
	circle(120,220,20);
    circle(190,220,20);
    circle(260,220,20);
	circle(330,220,20);

    circle(50,290,20);
	circle(120,290,20);
    circle(190,290,20);
    circle(260,290,20);
	circle(330,290,20);

	circle(50,360,20);
	circle(120,360,20);
    circle(190,360,20);
    circle(260,360,20);
	circle(330,360,20);

	circle(50,430,20);
	circle(120,430,20);
    circle(190,430,20);
    circle(260,430,20);
	circle(330,430,20);

   outtextxy(45, 140, "1");
   outtextxy(115, 140, "2");
   outtextxy(185, 140, "3");
   outtextxy(255, 140, "4");
   outtextxy(325, 140, "5");

   outtextxy(45, 210, "6");
   outtextxy(115, 210, "7");
   outtextxy(185, 210, "8");
   outtextxy(255, 210, "9");
   outtextxy(325, 210, "10");

   outtextxy(45, 280, "11");
   outtextxy(115, 280, "12");
   outtextxy(185, 280, "13");
   outtextxy(250, 280, "14");
   outtextxy(325, 280, "15");

   outtextxy(45, 350, "16");
   outtextxy(115, 350, "17");
   outtextxy(185, 350, "18");
   outtextxy(250, 350, "19");
   outtextxy(325, 350, "20");

   outtextxy(45, 420, "21");
   outtextxy(115,420, "22");
   outtextxy(185, 420, "23");
   outtextxy(250, 420, "24");
   outtextxy(325, 420, "25");

   outtextxy(100, 10, "|");
    outtextxy(100, 30, "|");
    outtextxy(100, 50, "|");
    outtextxy(100, 70, "|");
    outtextxy(100, 90, "|");

    outtextxy(180, 10, "|");
    outtextxy(180, 30, "|");
    outtextxy(180, 50, "|");
    outtextxy(180, 70, "|");
    outtextxy(180, 90, "|");

    outtextxy(10, 55, "----------------------------------------------------------------");


if (num==1){   outtextxy(10, 40, "player1:");
    outtextxy(10, 70, "computer:");
    outtextxy(120, 10, "score:");
    outtextxy(200, 10, "steps:");

    getch();
	closegraph();
}

if (num==2){
   outtextxy(10, 40, "player1:");
   outtextxy(10, 70, "player2:");
   outtextxy(120, 10, "score:");
   outtextxy(200, 10, "steps:");


}}
if(hardness==1 && num==1){

}
if(hardness==2 && num==2){

}
if(hardness==1 && num==2){ //easy and two players

}
if(hardness==2 && num==1){

}
if(exit==1){
     system("cls");


}

  }}}




