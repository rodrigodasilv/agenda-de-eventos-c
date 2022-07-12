// Constantes de erro
#define ERRO_LISTA_VAZIA	-1
#define ERRO_POS_INVALIDA	-2

// Elemento de lista
typedef struct ele {
	void *info;
	struct ele *proximo;
} Elemento;

// Cabeçalho de lista
typedef struct {
	Elemento *cabeca;
	int tamInfo, qtd;
} Lista;

void inicializa_lista( Lista *p, int t );
int lista_vazia ( Lista l );
int insere_inicio( Lista *p, void *info );
int remove_inicio( Lista *p, void *info );
int insere_fim( Lista *p, void *info );
int remove_fim( Lista *p, void *info );
int insere_pos( Lista *p, void *info , int pos );
int remove_pos( Lista *p, void *info , int pos );
int le_valor( Lista l, void *info , int pos );
int modifica_valor( Lista l, void *info , int pos );
void mostra_lista( Lista l, void (*mostra)(void *) );
void limpa_lista( Lista *l );
int insere_ordem( Lista *p, void *info, int (*compara)(void*, void*) );
void concatena( Lista *l1, Lista *l2 );
void concatena_v2( Lista *l1, Lista *l2 );
void mostra_lista_invertida( Lista l, void (*mostra)(void *) );
void salvar_lista(Lista l, void (*salva)(FILE *, void *), char* nome_arquivo);

int conta_elementos( Lista l ); // Função inútil na prática, pois temos o campo 'qtd'.
Lista busca_todos( Lista l, void *i, int (*compara)(void*,void*) );
