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
printf("\n\ntime p1 %d",p1.time%10);
printf(BLUE"\t\tSCORE: %d"RESET,play1.score);
printf(YELLOW"\n|\n____________________________________\n|"RESET);
printf(GREEN"\nPLAYER 2:  "RESET);
for(int i=0;play2.name[i]!='\0' &&play2.name[i]!='\n';i++){
    printf("%c",play2.name[i]);
}
printf("\n\ntime p2 %d",p2.time%10);
printf(GREEN"\t\tSCORE: %d"RESET,play2.score);
printf(YELLOW"\n|\n____________________________________\n"RESET);
printf(RED"\n\n\n\n\n\n\n\n\n\n\nINSTUCTIONS:\n"RESET);
printf(CYAN"TO MOVE: \npress any of the 4 arrow keys to move along the dots \nTO DRAW:\n press space with arrows"RESET);
printf(CYAN"for undo press=X\nfor exit the game press esc"RESET);

}

#endif // VIEW_H_INCLUDED
