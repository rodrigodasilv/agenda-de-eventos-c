#include "Hora.h"
#include "Data.h"

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
void mostraEvento(Evento *e);
void salva_evento(FILE* arquivo, Evento *e);