#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int* criarVetor(int n) {
	int i  = 0;
	int *v = malloc(sizeof(int) * n);
	
	for (i = 0; i < n; i++) {
		v[i] = rand() % n;
	}
	
	return v;
}

int pesquisaSequencial(int chave, int v[], int n) {
	int i = 0;
	int contador = 1;
	
	for (i = 0; i < n; i++) {
		contador++;
		
		if (v[i] == chave) {			
			return contador;
		}
		
		contador++;
	}
	
	return contador;
}

int main() {
	int n = 10;
	int* v = criarVetor(n);
	
	printf("melhor caso: %d\n", pesquisaSequencial(v[0], v, n));
	printf("pior caso: %d\n", pesquisaSequencial(v[11], v, n));
	printf("caso medio: %d\n", pesquisaSequencial(v[rand() % n], v, n));
	
	return 0;
}
