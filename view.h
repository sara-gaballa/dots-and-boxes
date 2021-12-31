#ifndef VIEW_H_INCLUDED
#define VIEW_H_INCLUDED
#include"structs.h"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"
void view(){
printf(YELLOW"____________________________________\n|"RESET);
printf(BLUE"\nPLAYER 1:  "RESET);
for(int i=0;play1.name[i]!='\0' && play1.name[i]!='\n';i++){
    printf("%c",play1.name[i]);
}
printf(BLUE"\n\nSCORE: %d"RESET,play1.score);
printf(BLUE"\n\nMOVES :  %d"RESET,play1.moves);
printf(YELLOW"\n|\n____________________________________\n|"RESET);
printf(GREEN"\nPLAYER 2:  "RESET);
for(int i=0;play2.name[i]!='\0' &&play2.name[i]!='\n';i++){
    printf("%c",play2.name[i]);
}

printf(GREEN"\n\nSCORE: %d"RESET,play2.score);
printf(GREEN"\n\nMOVES :  %d"RESET,play2.moves);
printf(YELLOW"\n|\n____________________________________\n"RESET);
printf(MAGENTA"\n\n\nNUM OF LINES LEFT =   %d"RESET,num_of_lines );


/*printf(CYAN"for undo press=X\nfor exit the game press esc"RESET);
printf(RED"\n\n\n\n\n\n\n\n\n\n\nINSTUCTIONS:\n"RESET);
printf(CYAN"TO MOVE: \npress any of the 4 arrow keys to move along the dots \nTO DRAW:\n press space with arrows"RESET);
*/
printf(RED"\n\nTIMMMMMME    %d"RESET,timenew);
if(num_of_lines==0){
        FILE *top10;
        top10=fopen("top10.txt","a");
    if(play1.score>play2.score){
        system("cls");
        printf("\n\n\t\tCONGRATLATIONS ");
        for(int i=0;play1.name[i]!='\0' && play1.name[i]!='\n';i++){
        printf("%c",play1.name[i]);
        }
         fprintf(top10,"%s",play1.name);
         fprintf(top10,"%d",play1.score);
        //return 0;
    }else if (play1.score<play2.score){
        system("cls");
        printf("\n\n\t\tCONGRATLATIONS ");
        for(int i=0;play2.name[i]!='\0' && play2.name[i]!='\n';i++){
        printf("%c",play2.name[i]);
        }
        fprintf(top10,"%s",play2.name);
        fprintf(top10,"%d",play2.score);
    }else{
            system("cls");
           printf("\n\n\t\tDRAW ");
    }
    fclose(top10);
}

}

#endif // VIEW_H_INCLUDED
