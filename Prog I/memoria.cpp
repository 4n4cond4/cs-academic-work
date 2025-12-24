#include<stdio.h>
#include<stdlib.h>

//TESTANDO TAMANHO DE MEMÓRIA

int main(){
	
	int a;
	float b;
	char x;
	double z; 
	
	printf("\n Uma variavel do tipo INT mede: %d bytes de memoria", sizeof a);
	printf("\n Uma variavel do tipo FLOAT mede: %d bytes de memoria", sizeof b);
	printf("\n Uma variavel do tipo CHAR mede: %d bytes de memoria", sizeof x);
	printf("\n Uma variavel do tipo DOUBLE mede: %d bytes de memoria", sizeof z);
	
	
	return 0;
}

