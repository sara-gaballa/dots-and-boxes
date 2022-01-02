#ifndef TOP10_H_INCLUDED
#define TOP10_H_INCLUDED
#include "structs.h"
void top(){
if(TOP10==0){
FILE *top10;
int i=0,x;
top10=fopen("top10.txt","a+");
if(play1.score>play2.score){
       for(int i=0;i<10;i++){
        if(topn[i].score==0){
        strncpy(topn[i].name,play1.name,50);
        topn[i].score=play1.score;
        break;}
        }
fprintf(top10,topn[i].name);
fprintf(top10,"\n%d\n",topn[i].score);
fclose(top10);
}
if(play1.score<play2.score && strcmp(compt,play2.name)!=0){

       for(int i=0;i<50;i++){
        if(topn[i].score==0){
        strncpy(topn[i].name,play2.name,50);
        topn[i].score=play2.score;
        break;}
        }
fprintf(top10,topn[i].name);
fprintf(top10,"\n%d\n",topn[i].score);
fclose(top10);
}

}

if(TOP10==1){
FILE *top10;
top10=fopen("top10.txt","r");
for(int i=0;i<50;i++){
fgets(topn[i].name,50,top10);
fscanf(top10,"%d",&topn[i].score);}
fclose(top10);
}
}
char temp[50]={};
void overwrriten(){//lsa
for(int i=0;i<50;i++){
        for(int x=i+1;x<50;x++){
            if(strcmp(topn[i].name,topn[x].name)==0 && strcmp(topn[i].name,temp)!=0 && strcmp(topn[x].name,temp)!=0){
                 if(topn[i].score>topn[x].score){
                    topn[x].score=0;
                    strncpy(topn[x].name,temp,50);
                 }
                 else if (topn[i].score<topn[x].score){
                    topn[i].score=0;
                    strncpy(topn[i].name,temp,50);
                 }
                 else if (topn[i].score==topn[x].score){
                    topn[x].score=0;
                    strncpy(topn[x].name,temp,50);
                 }
            }

}
}}
void sorting(){
for(int i=0;i<50;i++){
        for(int x=0;x<10;x++){
            if(topn[i].score>topn[x].score){
                swap(topn[x],topn[i]);
            }
        }
}

}


#endif // TOP10_H_INCLUDED
