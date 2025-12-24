#include <stdio.h>
#include <stdlib.h>
# define m 5
float val[m];
int i;
void imp(float v[]){
int i;
printf("\n\nImprime valores");
for(i=0; i < m; i++){
printf("\n[%d]= %.2f",i,v[i]);
}
} 

void main() {
printf("Escrevendo em um vetor: \n");
for(i=0; i<m; i++){
printf("[%d]=",i);
scanf("%f",&val[i]);
}
imp(val);
system ("pause");
}