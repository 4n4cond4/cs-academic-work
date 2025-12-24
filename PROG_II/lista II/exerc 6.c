#include<stdlib.h>
#include<stdio.h>
#include <time.h>
#define tm 100000

int v[tm];
int NumDados, dadProc, veri;


void OrdBolha (int *vt, int NDA){
    int i, j, aux;

    for(i = 0; i < NDA - 1; i++){
        for(j=0; j < NDA - 1 - i; j++){
            if(vt[j] > vt[j+1]){
             aux = vt[j];
             vt[j] = vt[j+1];
             vt[j+1] = aux;
            }
        }

    }
    
}
