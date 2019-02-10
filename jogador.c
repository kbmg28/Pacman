#include "mapa.h"
#include "jogador.h"


int main(){
	
	char input;
	carrega_mapa();
	
	do{
		system("cls");
		puts("\t\t\t UP:w\tDOWN:s\n\t\t\tESQ: a\t DIR: d\n");
		ver_mapa();
		input = getch();
		move (input);
	}while(jogoAcabou());
	
	
	
	libera_mapa();
	puts ("fim");
}

void move (char input){
	int x, y, erro=FALSE;
	
	for(i=0; i<m.linhas; i++){
		for (j=0; j<m.colunas; j++){
			//printf ("m.matriz[%d][%d]: %d", i, j, m.matriz[i][j]);
			if (m.matriz[i][j] == '@'){
				x = i;
				y = j;
				break;
			}
		}
	}
	
	switch (tolower(input)){
		
		case 'w': m.matriz[x-1][y] = '@'; break;
		case 's': m.matriz[x+1][y] = '@'; break;
		case 'a': m.matriz[x][y-1] = '@'; break;
		case 'd': m.matriz[x][y+1] = '@'; break;
		default: erro=TRUE;
	}
	
	if (!erro)
		m.matriz[x][y] = '.';
}

int jogoAcabou(){
	return 1;
}
