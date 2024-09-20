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

int pesquisaInterpolacao(int chave, int v[], int n) {
	int ini  = 0;
	int meio = 0;
	int fim  = n - 1;
	int contador = 0;
	
	contador++;
	if (v[ini] == v[fim]) return v[ini] == chave ? ini : -1;
	
	contador += 3;
	while (ini <= fim && chave >= v[ini] && chave <= v[fim]) {
		contador++;
		if (ini == fim) return v[ini] == chave ? ini : -1;
		
		meio = ini + (((double) (fim - ini) / (v[fim] - v[ini])) * (chave - v[ini]));
			
		contador++;
		if (chave == v[meio]) {
			return meio;
			
		} else if (chave < v[meio]) {
			fim = meio - 1;
			
		} else {
			ini = meio + 1;
		}
		
		contador += 4;
	}
	
	return contador; 
}

int main() {
	int n = 1000;
	int* v = criaVetor(n);
	
	printf("caso medio: %d\n", pesquisaInterpolacao(v[rand() % n], v, n));
	
	return 0;
}
