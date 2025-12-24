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

int BuscaBin (int vp, int NDA, int *vt){

int ME;
int AJ;
int ND;

ND = NDA -1;
AJ = 0;

while (AJ <= ND){
    ME = (AJ + ND) / 2;

    if(vt[ME] == vp){
        return ME;

    }
    if (vt[ME] < vp){
        AJ  = ME + 1;
    }

    else {
        ND = ME - 1;
    }

}
    return - 1;

}

int main(){

    int vr, di, h;
    printf("\tAlgoritmo Busca Binária e Ordenação Bolha\n");

    printf("\nDigite o numero de dados que o vetor vai suportar!\n");
    printf("NDPVS = ");
    scanf("%d", &NumDados);
    
    printf("\n\nIniciando vetor aleatoriamente\n\n");
    srand(time(NULL));

    for(h=0; h < NumDados; h++){
        vr = rand() % 100000;
        v[h] = vr;
    }

    OrdBolha(v, NumDados);

    for(h=0; h < NumDados; h++){
        printf(" %d ", v[h]);
    }

    veri = 1;
    while(veri != 2){
    
    printf("\n\nDigite o dado a ser procurado: ");
    scanf("%d", &dadProc);

    di = BuscaBin(dadProc, NumDados, v);

    if(di >= 0){
    printf("\nDado encontrado na posiçao: %d\n", di+1);
    }
    else{
        printf("Dado não encontrado!!!\n");
    }


    printf("\n1 - Continuar / 2 - Sair : ");
    scanf("%d", &veri);
    }

    return 0;
}
