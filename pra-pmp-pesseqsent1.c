#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int* criarVetor(int n) {
	int i  = 0;
	int *v = malloc(sizeof(int) * (n + 1));
	
	for (i = 0; i < n; i++) {
		v[i] = rand() % n;
	}
	
	return v;
}

int pesquisaSequencialSentinela(int chave, int v[], int n) {
	int i = 0;
	int contador = 1;
	v[n] = chave;
	
	contador++;
	while(v[i] != chave) {
		contador++;
		i++;
	}
	
	if (i < n) {
		return contador;	
	}
	
	return contador;
}

int main() {
	int n = 10;
	int* v = criarVetor(n);
	
	printf("melhor caso: %d\n", pesquisaSequencialSentinela(v[0], v, n));
	printf("pior caso: %d\n", pesquisaSequencialSentinela(n + 1, v, n));
	printf("caso medio: %d\n", pesquisaSequencialSentinela(v[rand() % n], v, n));
	
	return 0;
}
