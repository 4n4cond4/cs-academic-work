#include <stdio.h>
#include <unistd.h> // Para a função usleep()
// Função para exibir um ponto percorrendo a linha

void moverPonto(int largura, int delay) {
	
for (int i = 0; i < largura; i++) {
// Limpa a linha atual
printf("\r");

// Imprime espaços até o ponto
for (int j = 0; j < i; j++) {
	
printf(" ");
}

// Imprime o ponto
printf(".");

// Atualiza o terminal
fflush(stdout);

// Aguarda antes de mover
usleep(delay);

}

printf("\n"); // Adiciona uma nova linha ao final

}

int main() {
	
int largura = 50; // Largura da linha
int delay = 100000; // Delay em microssegundos

	printf("Movimento do ponto:\n");
	moverPonto(largura, delay);

return 0;

}
