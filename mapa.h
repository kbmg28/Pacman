typedef struct mapa{
	char** matriz;
	int linhas;
	int colunas;	
} MAPA;

MAPA m;

void carrega_mapa();
void ver_mapa ();
void libera_mapa ();
