#include "Hora.h"
#include "Data.h"
#include "Lista.h"
#define ERRO_SEM_ARQUIVO	-1

typedef struct{
	Data data;
	Hora inicio;
	Hora fim;
	char descricao[50], local[50];
} Evento;

int setEvento(Evento *e,Data data, Hora inicio, Hora fim, char descricao[50],char local[50]);
Data getData(Evento *e);
Hora getHoraInicio(Evento *e);
Hora getHoraFim(Evento *e);
char getDescricao(Evento *e);
char getLocal(Evento *e);
void mostraEvento(void *evento);
void salva_evento(FILE* arquivo, void *evento);
int carregar_lista(Lista *l, char* nome_arquivo);
int compara_evento( void *x, void *y );
int compara_evento_data( void *x, void *y );
void criaEvento(Evento *e);
int compara_evento_desc( void *x, void *y );
int compara_evento_hr_inicio( void *x, void *y );
void criaEventoInicio(Evento *e);
