#ifndef DEBUG_FINAL_SAVE_H_INCLUDED
#define DEBUG_FINAL_SAVE_H_INCLUDED
#include "structs.h"
#include "logic.h"
void final_save (){
FILE *debug;
debug=fopen("debug.txt","w");
fprintf(debug,play1.name);
if(player1==1){
fprintf(debug,"\n");}
fprintf(debug,play2.name);
fprintf(debug,"\n%d\n%d\n",play1.score,play2.score);
fprintf(debug,"%d\n",play1.moves);
fprintf(debug,"%d\n",play2.moves);
fprintf(debug,"%d\n",num_of_lines );
fprintf(debug,"%d\n",timenew);
fprintf(debug,"%d\n",N);
fprintf(debug,"%d\n",player1);
fprintf(debug,"%d\n",player2);
fprintf(debug,"%d\n",p1.color);
fclose(debug);
FILE *broaddebug;
broaddebug = fopen("broaddebug.txt","w");
for(int i=0;i<10;i++){
for(int l=0;l<10;l++)
for(int x=0;x<10;x++)
for(int z=0;z<10;z++)
fprintf(broaddebug,"%d\n",adj[i][l][x][z]);
}
fprintf(broaddebug,"\n");
for(int i=0;i<9;i++){
for(int l=0;l<9;l++)
fprintf(broaddebug,"%d\n",GRID[i][l]);}
fclose(broaddebug);

}

#endif // DEBUG_FINAL_SAVE_H_INCLUDED
