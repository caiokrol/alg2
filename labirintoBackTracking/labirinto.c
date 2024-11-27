//==========================================
//Author: Paulo R. Lisboa de Almeida
//Date:   7 Feb 2023
//==========================================

#include <stdio.h>

#define M 20
#define N 18
#define PAREDE 64
#define PASSAGEM 32
#define PASSOU 46

/*****
 * Importante: note que não está sendo utilizado size_t para os tamanhos, pois:
 * 1. Complicaria a leitura do teclado nos scanfs
 * 2. As matrizes que vamos lidar são suficientemente pequenas. Em um programa real, isso deveria ser
 * vericiado no main, por exemplo. Se um N grande o suficiente for usado, abortaríamos a execução
*****/

void imprimirLabirinto(int labirinto[][N]);
void lerLabirinto(int labirinto[][N], int*linInicio, int* colInicio, int* linFim, int* colFim);

struct s_coord{
	int lin;
	int col;
	int valor;
	int escolha;
};


int main(){
	int labirinto[M][N];
	int linhaInicio, colInicio, linhaFim, colFim;
	lerLabirinto(labirinto, &linhaInicio, &colInicio, &linhaFim, &colFim);
	imprimirLabirinto(labirinto);

	return 0;
}

void lerLabirinto(int labirinto[][N], int*linInicio, int* colInicio, int* linFim, int* colFim){
	scanf("%d %d %d %d", linInicio, colInicio, linFim, colFim);
	for(int i=0; i < M; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &labirinto[i][j]);
}

void imprimirLabirinto(int labirinto[][N]){
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			printf("%c",labirinto[i][j]);
		}
		printf("\n");
	}
}

int encontrar_saida_lab(int labirinto[][N], int* linFim, int* colFim, int linAtual, int colAtual){
	if(linAtual == linFim && colAtual == colFim){
		return 1;
	}

	if (labirinto[linAtual - 1][colAtual] == PASSAGEM){
		labirinto[linAtual - 1][colAtual] == PASSOU;
		encontrar_saida_lab(labirinto, linFim, colFim, linAtual, colAtual);
	}

	if (labirinto[linAtual][colAtual + 1] == PASSAGEM){
		labirinto[linAtual][colAtual + 1] == PASSOU;
		encontrar_saida_lab(labirinto, linFim, colFim, linAtual, colAtual);
	}
	if (labirinto[linAtual + 1][colAtual] == PASSAGEM){
		labirinto[linAtual + 1][colAtual] == PASSOU;
		encontrar_saida_lab(labirinto, linFim, colFim, linAtual, colAtual);
	}
	if (labirinto[linAtual][colAtual - 1] == PASSAGEM){
		labirinto[linAtual][colAtual - 1] == PASSOU;
		encontrar_saida_lab(labirinto, linFim, colFim, linAtual, colAtual);
	}
	
	return;
}