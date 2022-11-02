#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define ORGS 1000
#define GENES 20
#define ALLELES 4
#define MUT 1000

char **curG, **nextG, *mod;
int *f, totF, Eval(), Run();
int p1, p2;
void Mem(), Init(), Gen();

int main(){
  float pTime = omp_get_wtime();
  Mem();
  printf("The final generation was: %d\n", Run());
  float cTime = omp_get_wtime();
  printf("%f",cTime-pTime);
  }

void Mem(){
  int o;
  curG=(char**)malloc(sizeof(char*)*ORGS);
  nextG=(char**)malloc(sizeof(char*)*ORGS);
  mod=(char*)malloc(sizeof(char)*GENES);
  f=(int*)malloc(sizeof(int)*ORGS);
  for(o=0; o<ORGS; ++o){
    curG[o]=(char*)malloc(sizeof(char)*GENES);
    nextG[o]=(char*)malloc(sizeof(char)*GENES);
  }
}

int Run(){
  int gen=0;
  Init();
  while(++gen){
    if(Eval()) return gen;;
    Gen();}}

void Init(){
  int o, g;
  for(o=0; o<ORGS; ++o) for(g=0; g<GENES; ++g) curG[o][g]=rand()%ALLELES;
  for(g=0; g<GENES; ++g) mod[g]=rand()%ALLELES;}

int Eval(){
  int o, g, curF;
  for(totF=0, o=0; o<ORGS; ++o){
    for(curF=0, g=0; g<GENES; ++g) if(curG[o][g]==mod[g]) ++curF;
    if(curF==GENES) return 1;
    totF += f[o]=curF;}
  return 0;}

void Gen(){
  int o, g, cp;
  // #pragma omp parallel for
  // {
  int end = 1;
  for(o=0;o<ORGS;++o) {
    int j, tot=0, pt=rand()%(totF+1);
    
    // #pragma omp parallel for
    for(j=0; j<ORGS; ++j) {
      if(end == 1){
        if((tot+=f[j])>=pt) end = j;
      }
    }
    p1 = end;

    int k;
    tot=0;
    pt=rand()%(totF+1);
    end = 1;
    // #pragma omp parallel for
    for(k=0; k<ORGS; ++k) {
      if(end == 1){
        if((tot+=f[k])>=pt) end = k;
      }
    }
    p2 = end;

    for(p1,p2, cp=rand()%GENES,g=0;g<GENES;++g) {
      nextG[o][g]=(rand()%MUT)? ((g<cp)? curG[p1][g]: curG[p2][g]): rand()%ALLELES;
    }
  }


    #pragma omp parallel for collapse(2)
    for(o=0; o<ORGS; ++o){
      for(g=0; g<GENES; ++g){
        curG[o][g]=nextG[o][g];
      } 
    } 
  

}


