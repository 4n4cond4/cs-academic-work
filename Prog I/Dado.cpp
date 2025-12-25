#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//GERANDO NUMEROS ALEATORIOS DE 1 A 6

int Dado(int num){

int i;
		
srand(time(NULL));	
	
	
printf("%d", rand() %6);
i = getchar();

	
return i;	

}

int main(){
	
int aleatorio, nmr;

printf("DADO:\n\n");
printf("Numero de 1 a 6 sorteado foi: %d", aleatorio);


aleatorio = Dado(nmr);

return 0;
	
}









