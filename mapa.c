#include "jogador.h"
#include "mapa.h"


void ver_mapa (){
	for (i=0; i<m.linhas; i++)
		puts(m.matriz[i]);
}

void carrega_mapa(){
	FILE* arq = fopen("mapa.txt", "r+");
	char *tamanho;
	
	if (!arq){
		printf ("Erro na abertura do arquivo!\n");
		exit(0);
	}
	
	fscanf(arq, "%d %d", &m.linhas, &m.colunas);
	
	m.matriz = malloc (sizeof(char*) * m.linhas);
	
	for (i=0; i<m.linhas; i++){
		m.matriz[i] = malloc(sizeof(char) * (m.colunas + 1));
		fscanf (arq, "%s", m.matriz[i]);
	}
	
	fclose(arq);
}

void libera_mapa (){
	for (i=0; i<m.linhas; i++)
		free(m.matriz[i]);
	free (m.matriz);	
}

