#include "pacman.h"

int main(){
	
	carregando_mapa();
	
	ver_mapa();
	
	libera_memoria();
	puts ("fim");
}

void carregando_mapa(){
	FILE* arq = fopen("mapa.txt", "r+");
	char *tamanho;
	
	if (!arq){
		printf ("Erro na abertura do arquivo!\n");
		exit(0);
	}
	
	fscanf(arq, "%d %d", &linha, &coluna);
	
	mapa = malloc (sizeof(char*) * linha);
	
	for (i=0; i<linha; i++){
		mapa[i] = malloc(sizeof(char) * (coluna + 1));
		fscanf (arq, "%s", mapa[i]);
	}
	
	fclose(arq);
}

void libera_memoria (){
	for (i=0; i<linha; i++)
		free(mapa[i]);
	free (mapa);	
}

void ver_mapa (){
	for (i=0; i<linha; i++)
		puts(mapa[i]);
}

