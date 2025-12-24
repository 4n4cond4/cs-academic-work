#include<stdio.h>
#include<stdlib.h>

int BuscaBin (int vp, int TM, int *vt){

int IN; //inicio    
int ME; //meio
int FIM; //fim

FIM = TM -1;
IN = 0;

while (IN <= FIM){
    ME = (IN + FIM) / 2;

    if(vt[ME] == vp){
        return ME;

    }
    if (vt[ME] < vp){
        IN  = ME + 1;
    }

    else {
        FIM = ME - 1;
    }

}
    return - 1;

}