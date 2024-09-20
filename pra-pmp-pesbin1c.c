#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int compara(const void* a, const void* b) {
	return *(int*) a - *(int*) b;
}

int* criaVetor(int n) {
	int i  = 0;
	int *v = malloc(sizeof(int) * n);
	
	for (i = 0; i < n; i++) {
		v[i] = rand() % n;
	}
	
	qsort(v, n, sizeof(int), compara);
	
	return v;
}

int pesquisaBinaria(int chave, int v[], int n) {
	int inicio   = 0;
	int meio     = 0;
	int fim      = n - 1;
	int contador = 0;
	
	contador++;
	while (inicio <= fim) {
		meio = (inicio + fim) / 2;
		
		contador++;
		if (chave == v[meio]) {
			return meio;
			
		} else if (chave < v[meio]) {
			fim = meio - 1;
			
		} else {
			inicio = meio + 1;
		}
		
		contador += 2;
	}
	
	return contador;
}

int main() {
	int n = 100000;
	int* v = criaVetor(n);
	
	printf("melhor caso: %d\n", pesquisaBinaria(v[(n - 1) / 2], v, n));
	printf("pior caso: %d\n", pesquisaBinaria(n + 1, v, n));
	printf("caso medio: %d\n", pesquisaBinaria(v[rand() % n], v, n));
	
	return 0;
}
